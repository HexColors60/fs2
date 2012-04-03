inherit NPC;

void create()
{
        set_name("仙鹤", ({ "holy crane","crane" }) );
        set("race", "野兽");
        set("age", 3);
        set("long", "
一身雪白的羽翼，体态丰而不腴，娇而不媚，顾盼之间显得俗尘不染，翘
首之际分外灵动巧捷，或昂然而立，或翩然而趋，抑或展翅而翔，无不令
人神往。");
        set("str", 20);
        set("cor", 25);
        set("verbs", ({ "bite"}));
                set("limbs", ({ "头部", "身体",  }) );
        set("combat_exp",1000);
        set_temp("apply/armor", 15);
        set_temp("apply/attack", 10);
        set_skill("dodge",20);
        setup();

}
