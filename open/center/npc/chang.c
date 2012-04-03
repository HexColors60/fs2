// chang.c

#include "/open/open.h"

inherit NPC;

void create()
{
  set_name("橙儿", ({ "Chang", "chang" }));
  set("race", "人类");
  set("gender", "女性");
  set("age", 15);
  set("long", "一个很贴心的丫头, 总是守在楼梯口, 劝寻芳客不要打扰小姐休息.\n");
  set("attitude", "friendly");
  set("cor", 20);
  set("combat_exp",490);
  set("chat_chance", 2);

  set("chat_msg",({
    (: this_object() :),
    (: this_object() :),

    "橙儿说道∶小姐们都累了, 不要上去打扰她们好吗 ?\n",
    "橙儿说道 : 曲厅里有姑娘在唱小曲儿, 去看看吧 !\n",
    }));

  set_temp("apply/attack", 15);
  set_temp("apply/damage", 5);
  set_temp("apply/armor", 5);
  setup();
  carry_object(CENTER_OBJ"cloth2")->wear();
}
