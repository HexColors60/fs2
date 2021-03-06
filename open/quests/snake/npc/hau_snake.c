inherit NPC;
inherit SSERVER;
#include <ansi.h>

void create()
{
	set_name("化蛇",({"hau snake","snake"}));
	set("age",30);
	set("title",HIG"蛇寨三寨主"NOR);
	set("gender","男性");
        set("attitude","aggressive");
	set("long","
蛇寨三寨主，本名朱纨，后因修练邪灵。蛇鞭，走火入魔，误入
邪道，全身不幸长满蛇鳞，却也因此功力大进，成为蛇寨三寨主
，无恶不作，阴险至极。\n");
	set("max_gin",8000);
	set("max_kee",9000);
	set("max_sen",7000);
	set("max_force",10000);
	set("force",10000);
	set("force_factor",15);
	set("combat_exp",450000);
	set_skill("whip",110);
	set_skill("snake-whiper",110);
	set_skill("parry",110);
	set_skill("dodge",110);
	set_skill("move",110);
	set_skill("black-steps",110);
	set_skill("force",110);
	set_skill("snowforce",110);
	map_skill("whip","snake-whiper");
	map_skill("parry","snake-whiper");
	map_skill("dodge","black-steps");
	map_skill("move","black-steps");
	map_skill("force","snowforce");
	setup();
	carry_object(__DIR__"obj/s_whip")->wield();
	carry_object(__DIR__"obj/p_cloth")->wear();
	carry_object(__DIR__"obj/snake_gem")->wear();
}

void heart_beat()
{
object ob,env,target;
int i,j,k,kee,eff,max;

	ob = this_object();
	env = environment(ob);
	target = offensive_target(ob);

	if( !target )
		return ::heart_beat(1);

	max = (int)ob->query("max_kee");
	eff = (int)ob->query("eff_kee");
	kee = (int)ob->query("kee");

	if( ob->query_busy() && random(100) < 10 )
	{
		message_vision(HIW+"$N大喝一声～破～!!$N的奇经六脉回覆了正常!!\n"NOR,ob);
		ob->delete_busy();
	}

	if( random(100) < 50 )
	{
		if( eff < max || kee < eff )
		{
			message_vision(HIY"$N服下一贴毒药，以毒攻毒，将体内的瘀伤逼出～\n"NOR,ob);
			ob->receive_curing("kee",500);
			ob->receive_heal("kee",500);
			COMBAT_D->report_status(ob,1);
		}
	}

	if( env == environment(target) )
	{
		i = (int)ob->query_skill("dodge");
		j = (int)target->query_skill("dodge");
		k = (int)target->query_condition("fire_poison");
		
		if( random(i) > random(j) && k < 10 )
		{
			message_vision(HIG"$N左手一抛，一包灰色的纸包飞向$n，$n脸色突然一绿，似乎中毒了～\n"NOR,ob,target);
			target->apply_condition("fire_poison",k+3);
		}
	}
set_heart_beat(1);
::heart_beat();
}

void die()
{
object me,ob;

	ob = this_object();
	me = ob->query_temp("last_damage_from");

	message_vision(HIG"$N大喊：就算要死也要找一个陪葬～

$N回光返照的抱住了$n～

一瞬间，$N运功聚集所有毒素于口内，结果$N由于剧毒入脑，自暴了～\n"NOR,ob,me);
	me->apply_condition("snake_poison",10);
	me->receive_damage("kee",800);
	me->set("force",0);
	COMBAT_D->report_status(me,1);
::die();
}

