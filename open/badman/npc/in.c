// in.c by oda

#include </open/open.h>

inherit NPC;

void create()
{
	set_name("阴九幽", ({ "in ju yu", "in", "yu" }) );
	set("title", "恶人谷右护法");
	set("nickname", "半人半鬼");
	set("gender", "男性");
	set("class", "bandit");
	set("attitude", "badman");
	set("age", 42);
	set("long", "这个人看起来阳气全无，既像是大病垂死，更像是从棺材里爬出来的死人。\n江湖上传闻他的轻功超凡入圣，已到达来无影去无踪的境地，幽冥身法就是\n他发明出来的。\n他便是恶人谷的右护法，负责掌管谷内的人员调度。\n");

	set("str", 28);
	set("cor", 30);
	set("int", 23);
	set("spi", 30);
	set("cps", 29);
	set("con", 22);
	set("per", 19);
	set("combat_exp", 900000);
	set("max_force", 1200);
	set("force", 1200);
	set("force_factor", 10);
	set("max_gin", 1000);
	set("max_kee", 2500);
	set("max_sen", 1000);

	set_skill("badforce", 65);
	set_skill("badstrike", 90);
	set_skill("dodge", 100);
	set_skill("force", 55);
	set_skill("ghost-steps", 100);
	set_skill("move", 100);
	set_skill("parry", 40);
	set_skill("unarmed", 80);
	map_skill("force", "badforce");
	map_skill("unarmed", "badstrike");
	map_skill("parry", "badstrike");
	map_skill("dodge", "ghost-steps");
	map_skill("move", "ghost-steps");
	set("functions/evil-blade/level", 30);

	set("chat_chance_combat", 35);
	set("chat_msg_combat", ({
	(: perform_action, "unarmed.evil-blade" :),
	}));

	setup();
	add_money("gold", 10);
}
