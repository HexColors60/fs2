// ha.c by oda

#include </open/open.h>

inherit F_VENDOR;

void create()
{
	set_name("哈哈儿", ({ "ha ha er", "ha", "er" }) );
	set("nickname", "笑里藏刀笑弥陀");
	set("gender", "男性");
	set("age", 44);
	set("class", "bandit");
	set("attitude", "friendly");
	set("long", "你看到一个矮矮胖胖的圆脸胖子，脸上始终维持着一样的笑容，好像\n不会累似的。不过要是你因此而忽略了对他的防备的话，那可就大错\n特错啰。\n他是这家饭馆的掌柜，你可以向他买些东西吃。\n");
	set("vendor_goods", ({
	BAD_OBJ"meal",
	BAD_OBJ"luwei",
	BAD_OBJ"wine",
	}));

	set("combat_exp", 550000);
	set("str", 25);
	set("cor", 25);
	set("int", 30);
	set("spi", 23);
	set("cps", 21);
	set("con", 25);
	set("per", 22);
	set("max_force", 1000);
	set("force", 1000);
	set("force_factor", 10);
	set("max_gin", 500);
	set("max_kee", 1000);
	set("max_sen", 500);

	set_skill("array", 90);
	set_skill("blade", 60);
	set_skill("dodge", 45);
	set_skill("force", 40);
	set_skill("move", 40);
	set_skill("parry", 35);
	set_skill("unarmed", 30);
	set_skill("badstrike", 60);
	set_skill("badforce", 50);
	set_skill("ghost-steps", 40);
	map_skill("unarmed", "badstrike");
	map_skill("parry", "badblade");
	map_skill("force", "badforce");
	map_skill("dodge", "ghost-steps");
	map_skill("move", "ghost-steps");

	set("chat_chance", 8);
	set("chat_msg", ({
	"哈哈儿大笑道：哈哈，今天的天气不错，客人要不要吃点东西啊？哈哈。\n",
	"哈哈儿皮笑肉不笑的说：哈哈，我们这里的特制大餐\不错，肉质鲜美唷！哈哈。\n",
	}) );
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
	}) );

	setup();
	//carry_object(BAD_OBJ"liu_blade")->wield();
	add_money("gold", 10);
}

int accept_fight(object me)
{
	command("say 在下怎么可能是"+RANK_D->query_respect(me)+"的对手？您就别开我玩笑了。");
	remove_call_out("backstab");
	call_out("backstab", 3, me);
	return 0;
}

void backstab(object me)
{
	if(!me || environment(me)!=environment())
		return;
	message_vision("哈哈儿突然大喊了一声：‘纳命来！’，便朝着$N的背后攻了过去。\n",me);
	this_object()->kill_ob(me);
}
