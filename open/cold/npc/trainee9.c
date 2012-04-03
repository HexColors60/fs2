// bandit.c

inherit NPC;

void create()
{
	set_name("赵玉儿",({"yun"}));
	set("age",19);
	set("long",
		"她是寒谷一派的资深弟子，她的法术是掌门亲授，功力非同小可。\n");
	set("combat_exp",7000);
	set("score", 60);
	set("attitude","heroism");
	set_skill("unarmed",40);
	set_skill("parry",40);
	set_skill("force",30);
	set_skill("magic",70);
	set_skill("dodge",60);
	setup();
	add_money("silver", 3);
	create_family("玄冰寒谷",4,"弟子");
}
