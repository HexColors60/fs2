#include <ansi.h>
inherit F_VENDOR;

string magic1();
string magic2();

void create()
{
	set_name("志修",({"chishu"}) );
		set("long","他正在向他师父学习法术。\n");
        set("gender","男性");
        set("class","taoist");
        set("combat_exp",5000);
        set("attitude","heroism");
        set("age",17);
	 set("title","天道派第三代弟子");
        set("str", 25);
        set("cor", 24);
        set("cps", 25);
        set("per", 24);
        set("spi", 30);
        set("int", 26);
        set("force", 200);
        set_skill("literate",30);
        set("max_force", 200);
        set("max_mana",200);
        set("max_atman",150);
        set_skill("force",20);
        set_skill("gforce",20);
        map_skill("force","gforce");
        set_skill("dodge",20);
        set_skill("parry",20);
        set_skill("whip",30);
        set_skill("gwhip",20);
        map_skill("parry","gwhip");
        set("force_factor", 3);
        setup();
        carry_object("/open/tendo/obj/whisk1")->wield();
        carry_object("/open/tendo/obj/hat1")->wear();
        carry_object("/open/tendo/obj/shoe1")->wear();
        carry_object("/open/tendo/obj/robe1")->wear();
}
