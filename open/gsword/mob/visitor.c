// guard.c

inherit NPC;
void create()
{
        set_name("游客",({"visitor"}));
	set("gender", "男性" );
	set("age", 25);
	set("str", 10);
	set("cor", 25);
	set("cps", 25);
	set("int", 15);
	set("long",
		"一位来蜀山光观的游客.他正在游览四周的美景,\n"
		"一点也没在意你的到来...\n" );
        set("combat_exp", 400);
	set("attitude", "peaceful");
	set("chat_chance", 10);
	set("chat_msg", ({
                "游客说: 这蜀山风景真不错...\n",
                "游客说: 这里真是个好地方...\n",
                (: "random_move" :),
	}) );
	set_skill("dagger", 4);
	set_skill("parry", 15);
	set_skill("dodge", 25);
	setup();
        carry_object("/open/gsword/obj/map.c");
	add_money("silver",3);
        carry_object("/open/gsword/obj/robe")->wear();
        carry_object("/obj/example/dagger")->wield();
}
