// crazy_dog.c

#include "/open/open.h"
inherit F_VENDOR;

void create()
{
	set_name("王安", ({ "wang ani", "wang" ,"ani"}));
	set("title","仙剑派厨子");
	set("race", "人类");
	set("age", 53);
        set("long", "瞧他手执菜刀的姿势,便知道他是个一等一个大厨,
你可以看看他有些甚么(list).\n");
        set("vendor_goods", ({
                "/open/capital/obj/tea",
      "/open/gsword/obj/girl_wine",
      "/open/gsword/obj/green_wine",
                "/obj/example/dumpling",
                "/obj/example/chicken_leg",
        }) );
	set("attitude", "peaceful");
	set("str", 17);
	set("cor", 15);
	set("force",200);
	set("max_force",200);
	set("force_factor",2);
	set_skill("blade",20);
	set("combat_exp",4218);
	set_skill("blade",20);
	set_skill("her-blade",20);
	set_skill("force",20);
	set_skill("oneforce",20);
	set_skill("dodge",20);
	set_skill("parry",20);
	map_skill("blade","her-blade");
	map_skill("force","oneforce");
	setup();
       add_money("coin",50);
	carry_object("/open/gsword/obj/knife")->wield();
	carry_object("/open/gsword/obj/dirty_cloth")->wear();
}
