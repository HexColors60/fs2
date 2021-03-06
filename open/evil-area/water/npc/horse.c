inherit NPC;
#include <ansi.h>

void create()
{
	set_name("金锦马",({"golden horse","horse"}));
	set("age",9991);
	set("long","
一匹神态似鬼神的邪灵界战马，不过似乎已经有点年纪了。\n");
        set("str",30);
        set("cor",30);
        set("race","野兽");
        set("gender","雄性");
        set("max_gin",6000);
        set("max_kee",6000);
        set("max_sen",6000);
        set("max_force",20000);
        set("force",20000);
        set("force_factor",20);
        set("combat_exp",800000);
        set_skill("unarmed",300);
        set_skill("dodge",300);
        set_skill("move",300);
        set_skill("parry",300);
        set_skill("force",250);
        set("limbs",({"马头","马脚","马腿","马背","马腹"}));
        set("verbs",({"bite","claw"}));
        set_temp("apply/armor",100);
        set_temp("apply/defense",100);
        set_temp("apply/damage",100);
        set_temp("apply/attack",100);
        setup();
}

int accept_object(object me,object obj)
{
object ob = this_object();
int i;

	(int)me->add_temp("evil/water/horse",1);
	i = (int)me->query_temp("evil/water/horse");

	if( obj->query("id") == "cotton grass" )
	{
		if( (int)me->query_temp("evil/water/mission") == 2 && i > 3)
		{
			message_vision("$N"HIG"盯着$n一直看，接下来便低头缓缓的吃着棉草。\n"NOR,ob,me);
			(int)me->set_temp("evil/water/mission",3);
			me->delete_temp("evil/water/horse");
			call_out("do_dest",1,obj);
			return 1;
		}
	}
	me->receive_wound("gin",200);
	me->receive_wound("kee",300);
	me->receive_wound("sen",100);
	message_vision("$N"HIC"突然望向你，猛然转身提起后脚，狠狠的踹向$n～\n"NOR,ob,me);
	COMBAT_D->report_status(me,1);
	message_vision(HIY"$N被踹飞出了马厩\～\n"NOR,me);
	me->move("/open/evil-area/water/b-21");
call_out("do_dest",1,obj);
return 1;
}

int do_dest(object obj)
{
destruct(obj);
}