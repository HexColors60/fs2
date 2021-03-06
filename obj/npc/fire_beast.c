// garrison.c

#include <ansi.h>

inherit __DIR__"team";

string fight()
{
	object ob = query_leader();
	object *all = ob->query_enemy();
	object target = all[random(sizeof(all))];
	if( environment(ob) != environment(this_object()) ) return "";
	message_vision("$N"HIR"召唤出雄雄的地狱之火，朝$n喷去！\n",
	this_object(),target);
	if( random(query("power")) > random(target->query_skill("dodge")) )
	{
		message_vision("$n闪躲不及，被大火烧伤。\n",this_object(),target);
		message_vision(NOR,target);
		target->receive_wound("kee",query("power"));
		COMBAT_D->report_status(target);
	}
	else
		message_vision(HIY"$N躲了开来，没被火焰喷到。\n" NOR,target);
}
void create()
{
	set_name(HIR "地狱火神" NOR,({"fire beast","beast"}));
	set("race","野兽");

	set("combat_exp",10000);
	set("chat_chance_combat",60);
	set("chat_msg_combat", ({
		(: fight :),
	}) );

	set("verbs",({"bite","claw"}));
	set("limbs",({"头部","身体","脚部"}));
	set_skill("unarmed",10);
	set_skill("parry",10);
	set_skill("dodge",10);

	setup();

}

