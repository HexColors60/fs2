// guard.c

#include <ansi.h>

inherit NPC;
void create()
{
        set_name("城门守卫",({ "door guard","guard" }) );
	set("gender", "男性" );
        set("age", 35);
        set("str", 40);
        set("cor", 60);
	set("cps", 25);
	set("int", 15);
        set("long","蜀中城的守卫,他正看守着城门.\n");
	set("combat_exp",3241);
	set("attitude", "peaceful");
        set_skill("unarmed", 20);
        set_skill("parry", 25);
        set_skill("dodge", 25);
        set_skill("lungshan", 20);
        map_skill("dodge","lungshan");
        map_skill("unarmed","lungshan");
	setup();
	add_money("silver",20);
        carry_object("/open/gsword/obj/ring")->wear();
        carry_object("/open/gsword/obj/robe_3")->wear();
        carry_object("/open/gsword/obj/legging")->wear();
         	
}

