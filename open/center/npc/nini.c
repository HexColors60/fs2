// nini.c

#include "/open/open.h"

inherit NPC;

void create()
{
  set_name("小女孩", ({ "Nini", "nini" }));
  set("race", "人类");
  set("gender", "女性");
  set("age", 10);
  set("long","从小女孩的衣着看来, 应该是富贵人家的孩子, 不知怎么会出现在这个地方... 小女孩哭红了眼, 满头散发, 却还倔强的瞪着你.\n");
  set("attitude", "peaceful");
  set("cor", 18);
  set("combat_exp",180);
  set("chat_chance", 4);

  set("chat_msg",({
    (: this_object() :),
    (: this_object() :),

    "小女孩恨恨的说道 : 你不要以为我好欺负 !\n",
    "小女孩咬牙切齿的说道 : 你要是敢欺负我, 我爸爸会找你算帐的 !\n",
    }));

  set_temp("apply/attack", 15);
  set_temp("apply/damage", 5);
  set_temp("apply/armor", 5);
  setup();
}
