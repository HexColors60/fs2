inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
	set_name(RED"食蛊蛋"NOR,({"swallow gu egg","egg"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","
将万种蛊虫置放于蛊桶内，七七四十九天不放置任何食物，是其饥饿
并吞食其他的蛊类，只留下最强的蛊虫，在使用养蛊密法使其退化成
可食用的蛊蛋，吞食此种蛊蛋，任期生长于体内，其蛊虫成长，自然
能吞食百蛊，将体内的蛊虫、蛊卵、蛊蛹一并吞食，清除体内蛊毒，
可谓之百蛊之王。\n");
		set("value",100000);
		set("unit","盒");
		set("base_unit","粒");
	}
	set_amount(1);
	setup();
}

void init()
{
add_action("do_eat","eat");
}

int do_eat(string arg)
{
object me,env,ob;

	me = this_player();
	env = environment(me);
	
        if( !arg )
		return 0;

        arg=lower_case(arg);
        if( !ob = present(arg,me) )
		return 0;
        if( ob != this_object() )
		return 0;
	message_vision("$N吞食了一粒蛊蛋。\n",me);
	tell_object(me,HIR"
你感觉的到蛊蛋迅速成长，已经在你体内吞食了所有的蛊虫、蛊卵、以及蛊蛹。\n"NOR);
	me->delete_temp("evil_no_damage");
	me->delete_temp("evil_no_enemy");
	me->clear_condition("evil_pill01");
	me->clear_condition("evil_pill02");
	me->clear_condition("evil_poison");
	add_amount(-1);
return 1;
}	