// by roger

#include <ansi.h>
##include "castle.h"
inherit NPC;
void create() {
        
        set_name("骆玉婷",({"lo yu-ting","lo"}));
        set("title","湜雨厅主");
        set("long",@LONG
   她是林静诗从外面收留的小姑娘, 
   对她情同姐妹, 也教 导她武功与
   学问, 是个十分上进的女孩.
LONG);
        set("age",20);
        set("str",30);
        set("int",30);
        set("spi",30);
        set("cor",30);
        set("kar",30);
        set("cps",30);
        set("race","人类");
        set("gender","女性");
        set("attitude","aggressive");
        set("class","fighter");
        set("max_gin",3000);
        set("max_kee",3000);
        set("max_sen",3000);
        set("max_force",5000);
        set("force",5000);
        set("force_factor",10);
        set("combat_exp",1000000);
        set_skill("unarmed",100);
        set_skill("dodge",100);
        set_skill("lo-steps",100);
        set_skill("move",100);
        set_skill("parry",100);
        set_skill("wind-rain",100);
        set_skill("literate",150);
        set_skill("beauty-fingers",100);
        set_skill("force",150);
        map_skill("unarmed","beauty-fingers");
        map_skill("dodge","lo-steps");
        map_skill("parry","wind-rain");
        map_skill("move","lo-steps");
        set("clan_kill",1);
        setup();
        carry_object(C_OBJ"/sun_red_cloth")->wear();
        add_money("gold",10);
 }


