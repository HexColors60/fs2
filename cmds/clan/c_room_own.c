// c_room_own.c by ACKY

inherit F_CLEAN_UP;
#include <ansi.h>

int help( object me )
{
        write( @HELP
指令格式: c_room_own <ID>
指令说明: 设定所在之处为某人之专属区域。

	  c_room_own <ID>
	  取消某人之专属区域。

                                                by ACKY 08/17/2000
HELP);
        return 1;
}

int main( object me, string arg )
{
        string filename, file, *strs, owner;
        object env, who;
        int i;

	seteuid(getuid());
        if( !me->query("clan") )   return 0;
        if( !arg ) return help(me);
	if( me->query("clan/rank") > 3 )
                return notify_fail( "阶级不足以行使此权力。\n" );
        if( !CLAN_D->is_clan_room(me) && !wizardp(me) )
		return notify_fail( "此区域并非本帮所属地盘。\n" );
	who = find_player(arg=lower_case(arg));
	if(!who) who = FINGER_D->acquire_login_ob(arg);
        if(!who) return notify_fail( "查无此人。\n" );

	env = environment(me);
        filename = base_name(env) + ".c";
	file = read_file(filename);
	strs = explode( file, "\n" );

	if( owner=env->query("owner") ) {
		if( arg != owner )
			return notify_fail( "此处为 " + capitalize(owner) + " 的区域。\n" );
		if( who->query("clan/id") == me->query("clan/id") &&
			who->query("clan/rank") <= me->query("clan/rank") &&
			me->query("id") != owner )
			return notify_fail( "无权取消 " + capitalize(owner) + " 的区域。\n" );
		for( i=0; i<sizeof(strs); i++ )
        		if( strsrch( strs[i], "\"owner\"" ) != -1 ) break;
		file = implode( strs[0..i-1], "\n" ) + "\n" +
			implode( strs[i+1..<0], "\n" ) + "\n";
		env->delete("owner");
		CHANNEL_D->do_channel( me, "ct",
			"\n\t我 -「"HIW + me->query("clan/title") + HIY"”即日起取消……\n\t" +
			who->query("name") + "于"HIC + environment(me)->query("short") + HIY"的专属使用权。"NOR );
	}
	else {
	        for( i=0; i<sizeof(strs); i++ )
			if( strsrch( strs[i], "\"short\"" ) != -1 ) break;
		strs[i] += "\n\tset( \"owner\", \"" + arg + "\" );";
		file = implode( strs, "\n" ) + "\n";
		env->set( "owner", arg );
		CHANNEL_D->do_channel( me, "ct",
			"\n\t我 -「"HIW + me->query("clan/title") + HIY"”郑重的宣布……\n\t"
			HIC + environment(me)->query("short") + HIY"为" + who->query("name") + "的专属区域。"NOR );
	}

	write_file( filename, file, 1 );

	return 1;
}
