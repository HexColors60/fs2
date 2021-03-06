
#include <ansi.h>
#include "/open/open.h" 
inherit F_SOLDIER;
void create()
{
	set_name("将军",({"general"}) );
	set("long","
一位武艺不凡的将军，身上穿着铠甲，手上拿着宝剑，看起来十分威武。
据这里的村民说这位将军是在一次战役中负伤逃到此处，经村民救助后被
这里的风土人情深深的吸引，因此决定在此定居。\n");
	set("age",30);
	set("str",30);
	set("con",30);
	set("attitude","heroism");
	set("officer_power",50);
	set("max_officer_power",50);
	set("class","officer");
	set("soldier_list",([
	"soldier" : "兵士(soldier)",
	"fighter" : "武士(fighter)",
	"guard" : "守卫(guard)",
]) );
	set("soldier_lv",([
	"soldier" :5,
	"fighter" :10,
	"guard"   :15,
]) );
	set("max_kee",500);
	set("max_gin",500);
	set("max_sen",400);
	set("combat_exp",150000);
	set_temp("apply/armor",20);
	set_temp("apply/dodge",20);
	set_temp("apply/attack",30);
	set_skill("literate",60);
	set_skill("unarmed",40);
	set_skill("sword", 40);
	set_skill("blade",50);
	set_skill("move",40);
	set_skill("dodge",45);
	set_skill("nine-steps",40);
	set_skill("parry",45);
	set_skill("her-blade", 50);
	map_skill("move","nine-steps");
	map_skill("parry","her-blade");
	map_skill("dodge","nine-steps");
	map_skill("blade","her-blade");
	set("gender","男性");
	set("chat_chance_combat", 8);
	setup();
	add_money("gold",5);
	carry_object("/open/poison/obj/boots.c")->wear();
	carry_object("/open/poison/obj/plate.c")->wear();
	carry_object("/open/poison/obj/tblade.c")->wield();
	carry_object("/open/poison/obj/cloak.c")->wear();
	carry_object("/open/poison/obj/helmet.c")->wear();
}

void die()
{
	object me;
	me=query_temp("last_damage_from");
	message_vision("\n",me);
	message_vision(HIR "一大蓬的鲜血溅在你的脸上。\n" NOR,me);
	message_vision(" 将军的身体倒在血泊中微微地颤抖着。\n",me);
	tell_room(me,"将军说:你......你会害死村里的人....的。\n");
	call_out("msg2",1,me);
}
 void msg2(object me)
{	 
	message_vision("\n",me);
message_vision(HIG "山贼喽啰大叫:那个惹人厌的将军死掉啦，哈哈哈!!\n" NOR,me);

message_vision(HIG "山贼头目喊道:小子们，家伙准备好，要开工啦!!!\n" NOR,me);
	tell_room(me,"你不禁心想:糟!犯大错了。\n");
	new("/open/poison/npc/bandit4.c")->move("/open/poison/room/v2-6.c");
	new("/open/poison/npc/bandit2.c")->move("/open/poison/room/v2-6.c");
	new("/open/poison/npc/bandit1.c")->move("/open/poison/room/v2-4.c");
	new("/open/poison/npc/bandit1.c")->move("/open/poison/room/v2-4.c");
	new("/open/poison/npc/bandit2.c")->move("/open/poison/room/v2-2.c");
	new("/open/poison/npc/bandit1.c")->move("/open/poison/room/v2-2.c");
	new("/open/poison/npc/bandit1.c")->move("/open/poison/room/v2-1.c");
	new("/open/poison/npc/bandit1.c")->move("/open/poison/room/v2-8.c");
	::die();
	return 0;

}
