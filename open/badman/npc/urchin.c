#include <ansi.h>

inherit NPC;

void create()
{
      set_name("胖刺猬",({"fat urchin","urchin"}));
      set("long",@LONG
一只在树干下睡觉的胖刺猬；胖胖的模样十分讨人喜欢，让你忍不住想拍拍
它的头；但又看它满身的尖刺，想想还是算了吧。
LONG
      );

      set("race","野兽");
      set("gender","雄性");
      set("age", 4);
      set("attitude","peaceful");

      set("limbs",({"头部","腹部","前腿","尾巴","后腿"}));
      set("verbs",({"claw","bite"}));

      set("max_kee",150);
      set("kee",150);
      set_skill("dodge",10);
      set_temp("apply/armor",90);
      set_temp("apply/attack",30);
      set("combat_exp",740);

      set("chat_chance",1);
      set("chat_msg",({
          "胖刺猬抬起了头打了个大哈欠。\n",
          "胖刺猬抬起了头怔怔的瞧了你几眼。\n",
      }));

      setup();
}

void die()
{
      object killer;
      killer=query_temp("last_damage_from");
      killer->set_temp("blood",1);
      message_vision(HIR"\n几滴鲜血溅到了$N的衣服上。\n"NOR,killer);
      ::die();
}
