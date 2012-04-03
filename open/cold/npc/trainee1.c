// bandit.c

inherit NPC;

void create()
{
	set_name("秋儿",({"fall"}));
	set("gender","女性");
	set("age",15);
	set("long",
		"他看起来一脸稚气，可爱中带着一点秀气，她的名字叫秋儿。\n");
	set("combat_exp",8000);
	set("score", 60);
	set("attitude","heroism");
	set_skill("unarmed",40);
	set_skill("parry",40);
	set_skill("force",30);
	set_skill("magic",40);
	set_skill("dodge",60);
	setup();
	add_money("silver", 3);
	create_family("玄冰寒谷",5,"弟子");
}
