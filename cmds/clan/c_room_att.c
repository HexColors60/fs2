// c_room_att.c by ACKY
inherit F_CLEAN_UP;

#include <clanf.h>

string filename, file;

int help( object me );

int main( object me, string arg )
{
	object env;
	string type;

	seteuid(getuid());
	if( !me->query("clan") ) return 0;
	if( arg != "here" )      return help(me);
	if( !CLAN_D->is_clan_room(me) )
		return notify_fail( "此区域并非本帮所属地盘。\n" );
	env = environment(me);
	if( env->query("owner") != me->query("id") && me->query("clan/rank") > 3 )
		return notify_fail( "此处并非您的区域。\n" );
	filename = base_name(env) + ".c";
	file = read_file(filename);
	write( "将此" + ( env->query("light_up") ? "光亮" : "漆黑" ) + "区域设为 [1]光亮 [2]漆黑 : " );
	input_to( "ask_light", me );
	return 1;
}

void ask_light( string str, object me )
{
	int i, n;
	string *strs;

	strs = explode( file, "\n" );
	if( sscanf( str, "%d", n ) && n > 0 && n < 3 )
		if( n==1 ) {
			for( i=0; i<sizeof(strs); i++ )
				if( strsrch( strs[i], "\"light_up\"" ) != -1 ) break;
			if( i==sizeof(strs) ) {
				for( i=0; i<sizeof(strs); i++ )
					if( strsrch( strs[i], "\"short\"" ) != -1 ) break;
				strs[i] += "\n\tset( \"light_up\", 1 );";
			}
			else
				strs[i] = "\tset( \"light_up\", 1 );";
			file = implode( strs, "\n" ) + "\n";
		}
		else {
			for( i=0; i<sizeof(strs); i++ )
				if( strsrch( strs[i], "\"light_up\"" ) != -1 ) break;
			if( i<sizeof(strs) )
				file = implode( strs[0..i-1], "\n" ) + "\n" +
					implode( strs[i+1..<0], "\n" ) + "\n";
		}
	write( "将此" + ( environment(me)->query("outdoors") ? "室外" : "室内" ) + "区域设为 [1]室外 [2]室内 : " );
	input_to( "ask_outdoors", me );
}

void ask_outdoors( string str, object me )
{
	int i, n;
	string *strs;

	strs = explode( file, "\n" );
	if( sscanf( str, "%d", n ) && n > 0 && n < 3 )
		if( n==1 ) {
			for( i=0; i<sizeof(strs); i++ )
				if( strsrch( strs[i], "\"outdoors\"" ) != -1 ) break;
			if( i==sizeof(strs) ) {
				for( i=0; i<sizeof(strs); i++ )
					if( strsrch( strs[i], "\"short\"" ) != -1 ) break;
				strs[i] += "\n\tset( \"outdoors\", \"/open/clan/" + me->query("clan/id") + "\" );";
			}
			else
				strs[i] = "\tset( \"outdoors\", \"/open/clan/" + me->query("clan/id") + "\" );";
			file = implode( strs, "\n" ) + "\n";
		}
		else {
			for( i=0; i<sizeof(strs); i++ )
				if( strsrch( strs[i], "\"outdoors\"" ) != -1 ) break;
			if( i<sizeof(strs) )
				file = implode( strs[0..i-1], "\n" ) + "\n" +
					implode( strs[i+1..<0], "\n" ) + "\n";
		}
	write_file( filename, file, 1 );
	C_ROOM->update_keep( filename );
	write( "OK.\n" );
}

int help( object me )
{
	write( @HELP
指令格式: c_room_att here
指令说明: 修改目前所处区域之属性。
	  除了阶级三之外, 也可自行修改自己的区域。

						by ACKY 08/17/2000
HELP);
	return 1;
}
