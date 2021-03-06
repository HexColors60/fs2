inherit NPC;

void create() 
{
        set_name("水柪",({"water-worm","worm"}));
        set("long",
            "\n它是隐匿于水中的邪灵，一闻到生人气息就蹦出来吃人。\n");
        set("age",1937);
        set("str",30);
        set("cor",30);
        set("race","野兽");
        set("gender","雄性");
        set("attitude","aggressive");
        set("max_gin",6000);
        set("max_kee",6000);
        set("max_sen",6000);
        set("max_force",20000);
        set("force",20000);
        set("force_factor",20);
        set("combat_exp",800000);
        set_skill("unarmed",300);
        set_skill("dodge",300);
        set_skill("move",300);
        set_skill("parry",300);
        set_skill("force",250);
	set("evil_mob",1);
        set("limbs",({"头部","尾部","千节背","爪子"}));
        set("verbs",({"dunt","claw"}));
        set_temp("apply/armor",100);
        set_temp("apply/damage",100);
        setup();
}
