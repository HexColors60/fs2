#include </open/open.h>
inherit NPC;
void create()
{
  object ob;
  set_name("小童",({"boy"}));
  set("title", "看守");
  set("gender", "男性");
  set("class","killer");
  set("age",11);
  set("attitude", "killer");
  set("long", "他在此观看各个训练室的情形\t
你不要以为他是小孩子就好欺负,若没有一定程度,要杀他是不可能....\n");
   set_skill("rain-throwing",5);
   map_skill("throwing","rain-throwing");
  set("kee",4000);
  set("max_kee",4000);
  set("combat_exp",22345);
  setup();
    add_money("gold",5);
   ob=carry_object("/open/killer/obj/lustar.c");
   ob->add_amount(10);
    ob->wield();
}
