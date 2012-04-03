#include <ansi.h>
#include <dragon.h>
inherit NPC;

int kill_him(object);

void create() {
        set_name("血流漂杵泣花郎",({"ghost"}));
        set("long",
            "\n它看起来很凶恶，正注视着四周，看来它是饿了。\n");
        set("age",3000);
        set("gender","雄性");
        set("attitude","aggressive");
        set("max_gin",2500);
        set("max_kee",3000);
        set("max_sen",2500);
        set("max_force",2500);
        set("force_factor",10);
        set("combat_exp",1700000);
        set_skill("unarmed",100);
        set_skill("dodge",100);
        set_skill("nine-steps",100);
        set_skill("move",70);
        set_skill("parry",120);
        set_skill("hell-evil", 100);
        map_skill("unarmed", "hell-evil");
        map_skill("dodge","nine-steps");
        map_skill("parry","hell-evil");
        map_skill("move","nine-steps");
        setup();
 }

void init() {
        object obj;

        ::init();
        if(interactive(obj=this_player()) && !is_fighting()) {
           remove_call_out("kill_him");
           call_out("kill_him",0,obj);
        }
 }

void heart_beat()
{
        if( random(5) < 2 ){
        if(!is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
            if( query("eff_kee") < query("max_kee") )
                        command("exert heal");
                           }
        }
        :: heart_beat();
}       
