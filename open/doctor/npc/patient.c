
inherit NPC;
void create()
{
        set_name("病人", ({ "paitent" }) );
	set("gender", "男性" );
        set("age",45);
        set("str",35);
        set("cor",45);
	set("cps",25);
	set("int",15);
	set("long","病厌厌的他是来银针门看病的.\n");
	set("combat_exp",350);
	set("attitude", "peaceful");
        set("chat_chance", 25);
        set("chat_msg", ({
              "病人说: 好痛苦喔!!.\n",
              "病人说: 头痛,流鼻涕~\n",
        }) );
	set_skill("parry", 15);
        set_skill("dodge", 5);
	setup();
        add_money("coin", 25);
        carry_object("/obj/cloth")->wear();
         	
}


