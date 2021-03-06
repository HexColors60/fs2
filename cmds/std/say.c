// say.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if (!arg) {
		write("你自言自语不知道在说些什么。\n");
		message("sound", me->name() + "自言自语不知道在说些什么。\n",
			environment(me), me);
		return 1;
	}
	if( (int)me->query("kee") < (int)me->query("max_kee") / 5 ) {
		arg = replace_string(arg, " ", " ... ") + " ...";
	}

	arg = trans_color(arg);

write("‘"+HIG+"畅谈"+NOR+"’"+HIY+"你说道: " + arg + "\n"NOR); 
say("‘"+HIG+"畅谈"+NOR+"’"+HIY+me->name() + "说道: " +  arg + "\n" NOR, 
		environment(me), me);
	return 1;
}

int help (object me)
{
	write(@HELP
指令格式 : say <讯息>
指令说明 : 
           说话，所有跟你在同一个房间的人都会听到你说的话。
 
注 : 本指令可用单引号 ' 取代。
HELP
	);
	return 1;
}
