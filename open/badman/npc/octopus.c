// octopus.c by powell

inherit NPC;

void create()
{
      set_name("大章鱼",({"big octopus","octopus"}));
	set("long",
             "哇！这是一只八爪的大章鱼，有着长长的触手，可得小心一点，\n"+
             "可别成了牠的腹中物。\n"
    );

	set("race", "野兽");
	set("age", 200);
        set("attitude","aggressive");

	set("max_gin", 1000);
        set("max_kee",500);
	set("max_sen", 1000);

	set("str", 60);
	set("cor", 40);
	set("spi", 40);
	set("int", 60);

	set("limbs", ({ "头部", "身体", "触手" }) );
	set("verbs", ({ "bite", "claw" }) );

        set_skill("dodge",30);

        set_temp("apply/attack", 20);
        set_temp("apply/damage",30);
        set_temp("apply/armor", 80);

	set("combat_exp",99340);
	set("score", 100000);
	setup();
}
