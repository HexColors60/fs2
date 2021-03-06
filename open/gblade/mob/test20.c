// heaven_soldier.c

#include <ansi.h>

inherit NPC;

void create()
{

        set_name("八荒剑尊",({"wide sworder","sworder"}));
        set("long","
浓眉大耳，方脸宽额，眉宇间自有一股傲气，年轻时仗着自身精湛的剑术
，只身行走江湖，闯下了剑尊的名号，后来身染瘟疫，抑郁而终，化为冤
魂。\n");
        set("age",300);
        set("str", 30);
        set("no_exp",1);
        set("cor", 30);
        set("cps", 25);
        set("max_kee",1000);
        set("max_gin",500);
        set("max_sen",300);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",8);
        set("combat_exp", 400000);

        set("chat_chance_combat", 10);
        set("chat_msg_combat",({
                (: this_object(),"special_attack" :)
            }));
        set_skill("parry", 100);
         set_skill("dodge", 60);
        set_skill("sword",80);
        set_temp("apply/sword",70);
        set_temp("apply/dodge",50);
        set("attitude","peaceful");
        setup();
        carry_object("/open/gblade/mob/weapon18.c")->wield();

}


void invocation(object who)
{
        int i;
        object *enemy;

        message("vision",
        HIB"一道黑色的冤气从妖壶中奔泄而出\n"
        + name() + "冷笑地说：剑尊无敌，天命奈何！\n"NOR,
                environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                       kill_ob(enemy[i]);
                       if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
                       else enemy[i]->kill_ob(this_object());
                }
        }
        /*
        set_leader(who);
        */
}

        void special_attack()
 {
    object *enemy,target;
    int i;
        if(this_object()->query("force")>150)
        enemy=this_object()->query_enemy();
    i=sizeof(enemy);
    target=enemy[random(i)];
        message_vision(sprintf(HIB"
八荒剑尊劲运剑尖, 无形剑气在$N身上划下一道血淋淋的伤口
\n"NOR),target);
        target->add("kee",-100);
        this_object()->add("force",-100);
        COMBAT_D->report_status(target);
  }
