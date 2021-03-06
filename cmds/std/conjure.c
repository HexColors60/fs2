inherit F_CLEAN_UP;

int main( object me, string arg )
{
	string	magic, spl, trg;
	object	target;
	
	seteuid(getuid());

	if( me->is_busy() && !wizardp(me) )
		return notify_fail( "你用力聚集灵气, 发觉灵力一时难以发出。\n" );

   if(me->query("atman") < 0 ) {
   me->set("atman",0);
   tell_object(me,"没灵力了用什呀?\n");
   return 1;
   }
	if( environment(me)->query("no_magic") && !wizardp(me) )
		return notify_fail( "此处无法使用法术。\n" );

	if( !arg )
		return notify_fail( "指令格式: conjure <法术> [on <目标>]\n" );
	if( sscanf( arg, "%s on %s", spl, trg )==2 ) {
		target = present( trg, environment(me) );
		if( environment(me)->query("no_fight") || environment(me)->query("no_kill") )
			return notify_fail( "此处无法使用法术。\n" );
		if( !target )
			return notify_fail( "这里没有 " + trg + "。\n" );
		if( !living(target) )
			return notify_fail( "他不是生物。\n" );
		if( target->query("no_kill") )
			return notify_fail( "你不得对他施法。\n");
	}
	else {
		spl = arg;
		target = 0;
	}

	spl = replace_string( spl, " ", "_");

	if( stringp( magic = me->query_skill_mapped("magic") ) )
		return (int)SKILL_D(magic)->conjure_magic( me, spl, target );
	return notify_fail( "请先用 enable 指令选择所要使用的法术系。\n" );
}

int help (object me)
{
        write(@HELP
指令格式：conjure <法术名称> [on <对象>]
 
施法，你必需要指定<法术名称>，<对象>则可有可无。
在你使用某一个法术之前，你必须先用 enable 指令来指定你要使用的法术系。
 
HELP
        );
        return 1;
}
