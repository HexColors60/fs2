inherit NPC;
#include <ansi.h>

void create()
{
	set_name(HIY"黄金守卫"NOR,({"golden guard","guard"}));
	set("long","
长久以来被众神派首着震邪道的圣物圣灵, 由于身处震邪道的要道,
故被众神赋予掌管所有弱势生物的生杀大权, 你有一种直觉, 除非你
不想活了, 不然你绝对不会去挑战他的能力...\n");
        set("gender", "男性" );
	set("combat_exp",1000000);
	set("age",10000);
	set("max_kee",10000);
	set("max_sen",10000);
	set("max_gin",10000);
	set("chat_chance",10);
	set("unarmed",100);
	set("dodge",100);
	set("force",100);
	set("parry",100);
	set("chat_msg",({
"黄金守卫：除非你有黄金印，否则别想通过～!!\n",
}));
	setup();
}

int accept_object(object me,object ob)
{
	object obj=this_object();
	me=this_player();
	if(ob->query("id")!="golden seal")
	{
		message_vision("
$N大喝一声：破～!!"+ob->query("name")+"一瞬间化成一堆金沙，飞散四处。\n
$N大怒道：这不是我要的东西～!!\n",obj);
		destruct(ob);
		return 0;
	}
	if(!me->query_temp("evil/g_enter"))
	{
		message_vision("
$N大喝一声：破～!!"+ob->query("name")+"一瞬间化成一堆金沙，飞散四处。\n
$N大怒道：这东西要靠自己的实力拿到!!\n",obj);
		destruct(ob);
		return 0;
	}
	message_vision("
$N全身闪耀着金光～

$n恭恭敬敬的迎接$N，护送$N进入黄金门后，随即又将门关上～\n",me,obj);
	me->move("/u/f/firedancer/evil-area/e06");
	destruct(ob);
	return 1;
}


void die()
{
object me,ob,obj;
	ob=this_object();
	obj=new(__DIR__"golden_guard");
	me=ob->query_temp("last_damage_from");
	message_vision(HIR"
\n黄金守卫大怒：我乃管理着震邪道的〔圣灵〕-图妥，$N胆敢冒犯我！！去死吧！！\n\n"NOR,me);
	message_vision(HIW"$N化气成物，手中聚气为刀，一把极其锋利的黄金大刀挟器而来！\n
$N大喊：看我的～〔雄霸气皇〕～
$N手持黄金大刀直扑你的心脏，你闪躲不及，接连承受了好几刀!!\n"NOR,ob);
	me->receive_wood("kee",(int)me->query("kee")/2);
	COMBAT_D->report_status(me,1);
	COMBAT_D->report_status(me,1);
	COMBAT_D->report_status(me,1);
	message_vision(HIY"
$N再一个转身，手持黄金大刀再度直扑你的头部，你闪躲不及，生命已经命在旦夕!!\n"NOR,ob);
	me->set("kee",1);
	me->set("max_kee",1);
	COMBAT_D->report_status(me,1);
	COMBAT_D->report_status(me,1);
	COMBAT_D->report_status(me,1);
	message_vision(HIR"
$N瞬间高举黄金大刀，狠狠的往你的颈部一横劈。\n"NOR,ob);
	me->die();
	obj->move(environment(ob));
	destruct(ob);
}
