
inherit NPC;
void create()
{
        set_name("街民", ({ "man" }) );
	set("gender", "男性" );
        set("age",45);
        set("str",35);
        set("cor",45);
	set("cps",25);
	set("int",15);
	set("long",
                "一位普通的街民.\n"
                "他正忙着他的工作.\n");
	set("combat_exp",350);
	set("attitude", "peaceful");
        set("chat_chance", 25);
        set("chat_msg", ({
              "街民说: 城门守卫身上有还精丸.\n",
              "街民说: 本城桥上可装水...(fill 容器).\n",
              "街民说: 冰雪神戒和邪云神扇都是可怕的武器.\n",
              (: this_object(),"random_move" :),
        }) );
	set_skill("parry", 15);
        set_skill("dodge", 5);
	setup();
        add_money("coin", 25);
        carry_object("/obj/cloth")->wear();
        carry_object("/open/gsword/obj/g_pill");
         	
}

