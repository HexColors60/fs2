inherit NPC;
#include <ansi.h>
inherit SSERVER;

void create() 
{
        set_name("飞魑",({"fly-worm","worm"}));
        set("long",
            "\n它是暗藏于幻结界的邪灵，一闻到生人气息就蹦出来吃人。\n");
        set("age",1937);
        set("str",30);
        set("cor",30);
        set("race","野兽");
        set("gender","雄性");
        set("attitude","aggressive");
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
        set("limbs",({"头部","尾部","千节背","爪子","翅膀"}));
        set("verbs",({"dunt","claw","poke"}));
        set_temp("apply/armor",100);
        set_temp("apply/damage",100);
        setup();
}

void heart_beat()
{
	object ob,env,target;
	int sk1,sk2;

	ob = this_object();
	env = environment(ob);
	if(random(100) < 70)
	{
    	target = offensive_target(ob);
	sk1 = (int)ob->query_skill("parry");
	sk2 = (int)target->query_skill("parry");
		if( env == environment(target) && random(sk1) > random(sk2))
		{
                message_vision("
\n$N"HIR"口吐熊熊烈火，$n一不小心被灼伤了。\n"NOR,ob,target);
                COMBAT_D->report_status(target,1);
                target->start_busy(2);
		}
	}
set_heart_beat(1);
::heart_beat();
}

void die()
{
object ob,me,obj;
        ob=this_object();
        me=ob->query_temp("last_damage_from");
        me->add_temp("evil/road_kill",1);
        if(random(100) < 50 && (int)me->query_temp("evil/road_kill") > random(10)+10 )
        {
                message_vision("$N在胸口掏出一个东西, $n眼明手快的抢了过来。\n",ob,me);
                tell_object(me,"你得到了一个噬虫。\n");
                obj=new(__DIR__"obj/worm");
                obj->move(me);
                me->delete_temp("evil/road_kill");
        }
::die();
}
