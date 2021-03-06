inherit NPC;

void create()
{
        set_name("段王府侍卫",({"duan guard","guard"}));
        set("long","
满脸和善的笑容中隐含着一股不容侵犯的威严，望着他不怒自威的眼神，
使得你内心的作歹念头，一扫而空。
");
        set("gender","男性");
        set("combat_exp",80000);
        set("attitude","heroism");
        set("age",30);
        set_skill("unarmed",60);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("force", 20);
        set_skill("sunforce",10);
        set_skill("six-fingers",50);
        set("force",300);
        set("max_force",300);
        set("force_factor",5);
        set_skill("linpo-steps",30);
        map_skill("force", "sunforce");
        map_skill("unarmed", "six-fingers");
        map_skill("dodge", "linpo-steps");
        set("race", "人类");
                setup();
        add_money("silver",70);

}

