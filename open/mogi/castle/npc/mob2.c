//by roger
#include <ansi.h>
inherit NPC;

int kill_him(object);

void create() {
        
        set_name("追影鬼仆",({"ghost"}));
        set("long",
            "\n一只全身黄毛，头上长着三只角的恶妖。\n");

        set("age",3021);
        set("str",30);
        set("cor",30);
        set("race","野兽");
        set("gender","雄性");
        set("attitude","aggressive");
        set("max_gin",2400);
        set("max_kee",6200);
        set("max_sen",3000);
        set("max_force",6200);
        set("force",6000);
        set("force_factor",10);
        set("combat_exp",1900000);
        set_skill("unarmed",90);
        set_skill("dodge",95);
        set_skill("nine-steps",95);
        set_skill("move",90);
        set_skill("parry",90);
        set_skill("hell-evil", 90);
        map_skill("unarmed", "hell-evil");
        map_skill("dodge","nine-steps");
        map_skill("parry","hell-evil");
        map_skill("move","nine-steps");
        set("limbs",({"头部","胸部","大角","黄脚","背部","腰部"}));
        set("verbs",({"bite","claw"}));
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

/*   此先暂时不用  int kill_him(object obj) {
//        if(obj->query("race") == "妖怪") return 1;
        if(obj->query("race") == "野兽") return 1;
        if(obj->query("max_force") > 999 ||
           obj->query("combat_exp") > 299999)
           command("kill "+obj->query("id"));
        return 1;
}*/
