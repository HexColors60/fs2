inherit NPC;

void create()
{
seteuid(getuid());
         set_name("魔刀入门弟子",({"trainee"}));
        set("gender", "男性" );
        set("age", 19);
         set("long", "一位刚加入魔刀门的弟子..\n");
          set("combat_exp",15000);
        set_temp("apply/attack",10);
         set_skill("dodge",25);
         set_skill("parry",25);
         add_money("coin",200);
        setup();
}

