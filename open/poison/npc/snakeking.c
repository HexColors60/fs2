#include <ansi.h>
#include "/open/open.h"
inherit NPC;

void create()
{
	set_name("毒龙王",({ "dragon king", "king" }) );
	set("age",500);
	set("gender","雄性");
	set("race","野兽");
	set("limbs",({"头部","尾部","腹部"}));
	set("verbs",({"bite"}) );
	set("combat_exp",40000);
	set_skill("dodge",80);
	set("attitude","aggressive");
	set_temp("apply/armor", 50);
	set_skill("unarmed",40);
	set("long","
一条巨大的毒龙。
\n");
	set("str",40);
	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
	(: "special_att" :),
}) );
	setup();
	carry_object("/obj/source/dragon_heart.c");
}
 int special_att()
{
	object me=this_player()->query_enemy();
	tell_room(me,HIG "
巨蟒狠狠的咬了你一口，你突然觉得头昏眼花，似乎中毒了。\n" NOR );
	me->apply_condition("snake_poison",me->query_condition("snake_poison")+5);
	return 1;
}
