// hen.c by nako
// use in /open/start by nako

inherit NPC;

void create()
{
        set_name("母鸡", ({ "hen" }) );
        set("long", "农家常见的家禽, 正四处寻找着食物。\n");
	set("race","野兽");
        set("age", 5);
        set("str", 10);
	set("con", 9);
	set("max_gin", 60);
        set("max_kee", 80);
	set("max_sen", 60);

        set("limbs", ({ "喙子", "头部", "脖子", "翅膀", "爪子" }) );
        set("verbs", ({ "claw", "poke" }) );
	set("chat_chance", 4);
	set("chat_msg", ({
                "母鸡走着走着, 忽然从地上啄起一只虫子。\n",
	}) );
		
        set("combat_exp", 100);
	setup();
        carry_object("/open/start/obj/egg.c");
}
