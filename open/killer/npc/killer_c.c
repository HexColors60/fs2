#include <ansi.h>
inherit NPC;
void create()
{
    set_name("二级杀手教头",({"trainer"}) );
    set("long",
   "黑牙联的实战教练,专门与来此练习的人对招，不管各门各派\n");
    set("race", "人类");
    set("gender","男性");
     set("combat_exp",50000);
    set("age",40);
    set("title","黑牙联成员");
    set("kee",300);
    set("max_kee",300);
    set("bellicosity",350);
    set_skill("sword",55);
    set_skill("dodge",45);
    set_skill("parry",45);
    set_skill("shadow-kill",35);
    map_skill("sword","shadow-kill"); 
    set("chat_chance", 3);
    set("chat_msg", ({ (: this_object(), "random_move" :),
    "教头愤怒地说: 小子,别偷懒 !\n",
 }));
    setup();
   carry_object("/open/gsword/obj/woodsword")->wield();
   add_money("silver",45);
}