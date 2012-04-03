inherit NPC;
void create()
{
        set_name("苏金泉",({"gin-chun su","su","gin-chun"}));
        set("long","华陀的爱徒,平时对医术很有兴趣,如今他以可以独当一面。\n");
        set("gender","男性");
        set("title","银针门弟子");
        set("nickname","有医无类");
        set("max_force",1500);
        set("force",1500);
        set("max_kee",1000);
        set("force_factor",10);
        set("combat_exp",500000);
        set_skill("stabber",50);
        set_skill("dodge",50);
        set_skill("parry",40);
        set_skill("poison",40);
        set_skill("move",50);
        set_skill("force",45);
        set_skill("cure",40);
        set_skill("yu-needle",75);
set_skill("seven-steps",80);
        set_skill("godcure",50);
        set_skill("shinnoforce",50);
        map_skill("force","shinnoforce");
        map_skill("parry","yu-needle");
        map_skill("stabber","yu-needle");
map_skill("move","seven-steps");
        map_skill("cure","godcure");
map_skill("dodge","seven-steps");
        set("apply/attack",20);
        set("apply/dodge",30);
        setup();
        add_money("gold",5);
        carry_object("/open/doctor/obj/needle4.c")->wield();
}
void greeting(object ob)
{
        if( (string)ob->query("class") == "poisoner" )
{
        command("say 师父生平最恨毒害苍生之人,今日我便为师除害,纳命吧！");
        kill_ob(ob);
}
}


