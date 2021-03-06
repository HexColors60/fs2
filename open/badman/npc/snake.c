#include </open/open.h>
#include <ansi.h>

inherit NPC;
inherit SSERVER;

int do_attack();

void create()
{
      set_name("毒蛇",({"snake"}));
      set("long","一只头成三角状的毒蛇，正盘成一团不停的吐着舌信。\n");
      set("race","野兽");
      set("gender","雄性");
      set("age",10);
      set("attitude","peaceful");

      set("limbs",({"头部","三寸","七寸","尾巴"}));
      set("verbs",({"bite"}));
      set("max_kee",150);
      set("kee",150);
      set_skill("dodge",10);
      set_temp("apply/armor",20);
      set_temp("apply/attack",30);
      set("combat_exp",1000);

      set("chat_chance",1);
      set("chat_msg",({
          "毒蛇吐了吐蛇信，瞧了瞧四周的状况。\n",
      }));

      set("chat_chance_combat",35);
      set("chat_msg_combat",({
         (:do_attack:),
      }));

      setup();
}

int do_attack()
{
      object me = offensive_target(this_object());
      int M;
      M=(int)me->query_condition("snake_poison");

      if( me->query_skill("dodge")>=30 ) {
        message_vision("毒蛇想一口咬住$N，但被$N轻松的躲开了。\n",me);
        return 0;
      }

       else if( random(2)>=1 ) {
         message_vision("毒蛇扑上来想要咬$N，但被$N一掌带歪了准头。\n",me);
         return 0;
       }

      else  {
        me->apply_condition("snake_poison",M+3);
        if( M==0 ) {
          message_vision(HIR"$N一个不小心，被毒蛇咬了一口，中毒了。\n"NOR,me);
          return 1;
        }
        else {
          message_vision(HIB"$N又被毒蛇咬了一口，中毒加深了。\n"NOR,me);
          return 1;
        }
        return 1;
      }
      return 1;
}
