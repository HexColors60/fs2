inherit NPC;
void create()
{
        set_name("皇柏壬",({"huang-bo ren","ren",}));
        set("gender","男性");
        set("age",40);
        set("str",45);
        set("bellicosity", 2000);
        set("title","猴王");
        set("long","曾是一代高手 ,因某种原因被魔教关来此地 ,百般无聊下习得操猴术 ,
便成为此地的猴王 !\n");
          set("combat_exp",700000);
        set("max_kee",1700);
        set("kee",1700);
        set("max_force",2000);
        set("force",2000);
        set_skill("unarmed",90);
        set_skill("parry",40);
        set_skill("dodge",40);
        set_skill("force",90);
        set_skill("badstrike",90);
        set_skill("black-steps",60);
        set_skill("badforce",80);
        map_skill("unarmed","badstrike");
        map_skill("parry","badstrike");
        map_skill("dodge","black-steps");
        map_skill("force","badforce");
        
        setup();
}

