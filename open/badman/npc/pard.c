#include <ansi.h>

inherit NPC;

void create()
{
      set_name("金钱豹",({"pard"}));
      set("long",@LONG
一只罕见的金钱豹，一身有着如金钱般的花纹；在树上以两颗铜玲般的大眼虎
视眈眈的望着你，再加上脚上那两对锐利如刀的豹\爪，便是提醒你快些离开的
最佳证据。
LONG
      );

      set("race","野兽");
      set("gender","雄性");
      set("age", 5);
      set("attitude","peaceful");

      set("limbs",({"头部","腹部","前腿","尾巴","后腿"}));
      set("verbs",({"bite","claw"}));

      set("max_kee",150);
      set("kee",150);
      set_skill("dodge",55);
      set_temp("apply/armor",40);
      set_temp("apply/attack",70);
      set("combat_exp",6500);

      set("chat_chance",1);
      set("chat_msg",({
          "金钱豹\起身飞纵至另一棵树上。\n",
          "金钱豹\跳下树来，在你的身旁绕了几圈。\n",
          "金钱豹\打了个大哈欠，露出一口雪白尖锐的牙齿；吓出你一身的冷汗。\n",
      }));

      setup();
}

void init()
{
      object me=this_player();
      ::init();
      if( me->query_temp("blood")==1 ) {
      message_vision(HIB"\n金钱豹\闻到$N身上的血腥味，一声狂啸、便扑向$N。\n"NOR,me);
      this_object()->kill_ob(me);
      }
}
