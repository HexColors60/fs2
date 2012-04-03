inherit NPC;

void create()
{
      set_name("人身双尾蛇",({"ditail-snake"}));
        set("long","伏羲式饲养的宠物之一,性极暴燥,其两条尾巴各具有不同的能力!!\n"    );
        set("race", "野兽");
        set("age", 110);
       set("attitude","aggressive");    
        set("max_kee",2500);
        set("str", 110);
        set("cor", 40);
        set("spi", 40);
        set("int", 60);
        set("limbs", ({ "头部", "身体", "前脚", "后腿", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set_temp("apply/attack", 70);
        set_skill("dodge",50);
        set_temp("apply/damage", 160);
        set_temp("apply/armor", 50);
        set("combat_exp",50000);      
        setup();
}            