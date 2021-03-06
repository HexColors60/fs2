#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
	set_name("殿前武士",({"fighter"}));
	set("gender","男性");
	set("class","poisoner");
	set("long","一个全副武装的武士,正在此处守卫。\n");
	set("combat_exp",22000);
	set("age",26);
		set("str", 44);
		set("cor", 24);
		set("cps", 18);
		set("per", 24);
		set("int", 42);
	set_skill("parry", 20);
	set_skill("dodge",35);
	set_skill("move", 30);
	set_skill("unarmed", 20);
	set_skill("poison",30);
	set_skill("nine-steps",33);
	set_skill("ming-snake",40);
	set_skill("whip", 40);
	set_skill("force",20);
	set("poisonforce", 30);
	set("nine-steps", 40);
	map_skill("dodge", "nine-steps");
	map_skill("force","poisonforce");
        set("attitude","heroism");
	set("max_kee",300);
	set("max_gin",300);
	set("max_sen",300);
	
	set("force",300);
	set("max_force",300);
	set("chat_chance" ,8);
	set("chat_msg", ({
		"武士说道:非冥蛊教中人请速速离开.\n",
		"武士说道:此处乃冥蛊教总坛所在.\n",
		 
}) );
	 
	setup();
	add_money("silver", 20);
	carry_object("/open/poison/obj/ecloth.c")->wear();
	carry_object("/open/poison/obj/ebelt.c")->wear();
	carry_object("/open/poison/obj/longwhip.c")->wield();
	carry_object("/open/poison/obj/armband.c")->wear();

}

