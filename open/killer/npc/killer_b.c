#include <ansi.h>
inherit NPC;
void create()
{
    set_name("一级杀手教头",({"trainer"}) );
    set("long",
   "黑牙联的实战教练,专门与来此练习的人对招，不管各门各派\n");
    set("race", "人类");
    set("gender","男性");
     set("combat_exp",100000);
    set("age",40);
    set("title","黑牙联成员");
    set("kee",400);
    set("max_kee",400);
    set("bellicosity",350);
    set_skill("sword",65);
    set_skill("dodge",60);
    set_skill("parry",60);
    set_skill("shadow-kill",50);
    map_skill("sword","shadow-kill"); 
    set("chat_chance", 3);
    set("chat_msg", ({ (: this_object(), "random_move" :),
    "教头愤怒地说: 小子,别偷懒 !\n",
 }));
    setup();
   carry_object("/open/gsword/obj/woodsword")->wield();
   add_money("gold",1);
}