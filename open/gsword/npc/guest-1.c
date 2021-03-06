inherit NPC;

void create()
{
	set_name("林南生",({"non son","son"}));
	set("long","封山弟子 ,师父派他来仙剑处理事务 .\n");
	set("gender","男性");
	set("combat_exp",183110);
        set("attitude","heroism");
	set("age",25);
	set("class","swordsman");
	set("score",1000);
	set("force",300);
        set("max_force",300);
	set("force_factor",3);
	set("str",30);
        set("cor", 30);
	set("per", 25);
	set("int", 30);
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	set_skill("sword",40);
	set_skill("dodge",40);
	set_skill("parry",40);
	set_skill("fonxansword",60);
	set_skill("force",40);
	map_skill("sword","fonxansword");
	map_skill("parry","fonxansword");
	set("chat_chance_combat",40);
	set("chat_msg_combat",({
	 (:perform_action,"sword.counterattack":)
        }));
	setup();
	carry_object("/obj/longsword.c")->wield();
	carry_object("/open/gsword/obj/robe_1")->wear();
	// 怎么每个人都有同样的东西咧?
	// carry_object("/open/gsword/obj/pill")->set_amount(5);
	create_family("封山派",15,"弟子");
}
