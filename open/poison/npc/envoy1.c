#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
        set_name("传道使",({"envoy"}));
	set("gender","男性");
	set("class","poisoner");
	set("combat_exp",30000);
	set("age",26);
	set("long","魔教七大使之一，专司传述魔教教义之职。\n");
		set("str", 44);
		set("cor", 24);
		set("cps", 18);
		set("per", 24);
		set("int", 42);
	set("force",450);
	set("max_force",450);
	set_skill("unarmed",10);
	set_skill("parry",20);
	set_skill("dodge",20);
	set_skill("whip",20);
	set_skill("force",10);
	set_skill("poisonforce",15);
	set_skill("poison",16);
	set_skill("ming-snake",25);
	set_skill("coldpoison",40);
	set_skill("nine-steps",30);
	map_skill("dodge","nine-steps");
	map_skill("force","poisonforce");
	map_skill("whip","ming-snake");
	map_skill("parry","ming-snake");
	setup();
carry_object("/obj/poison/rose_poison")->set_amount(5);
carry_object("/obj/poison/five_poison")->set_amount(5);
carry_object("/obj/poison/dark_poison")->set_amount(5);
carry_object("/obj/poison/faint_poison")->set_amount(5);

	carry_object("/open/poison/obj/longwhip.c")->wield();
}

