#include <ansi.h>
inherit SKILL;
void striback(object me,object victim);

string *parry_msg = ({
 "$n瞧着$N的攻势，脚步一转，吓然转出了一式[1;37m‘邪岚转势’[0m，瞬间变制住了$N的攻势，转守为攻\n",
 "$n大喝一声，趁$N击出一击重击时，使出一招[1;36m‘凶兆舞势落’[0m，$N的身子硬是逆着$N的攻势逼到$N身前\n",
 "$n注视着$N的层层攻势，脚锋一捷，点出了一记[1;35m‘杀元跺’[0m，便趁着$N的攻势尚未使尽前架住其锋，硬是把$N元气退回，使得$N元气颇伤\n",
 "$n注意到$N即将展开攻势，随即将身法放轻，内力凝聚，用出了一招[1;34m‘厄惊觉’[0m，$n看准了$N的攻势尚未展开便扣住其身，虎口正对准了$N那尚未明了的脸孔上\n",
 "$n眼看着$N强大攻势即将落在$n身上，忽然心神一震，脚步急转成风，使出的正是[1;31m‘无心诀’[0m，只见得$N的身子忽然凝滞不前，$n正在$N头上攻下\n",
                    });

int valid_enable(string usage)
{
  object me=this_player();
  if ( me->query("class") == "bandit" )
    return (usage=="parry");
 else
    return notify_fail("你又不是个坏东西 ,凭啥用这招 ?\n");
}

string query_parry_msg(string limb)
{
  int sb;
  object me=this_player();
  sb = me->query_skill("evilstriback");
  if ( sb <= 80 )
  {
    call_out("striback",me);
  return parry_msg[random(4)];
  }
  else
  {
    call_out("striback",me);
  return parry_msg[random(sizeof(parry_msg))];
  }
}

int valid_learn(object me)
{
  if(me->query_skill("badstrike",1)<30)
    return notify_fail("拳脚功夫不扎实还想有番作为 ?\n");
  else if (me->query_skill("badforce",1)<30)
    return notify_fail("先学着运气吧 ,小子\n");
  else if (me->query_skill("ghost-steps",1)<30)
    return notify_fail("轻功不高还想要制敌机先 ?\n");
  return 1; 
}

void striback(object me,object victim)
{
  int esb;
  esb = (me->query_skill("evilstriback")/10);
  if ( random(esb) >= 5 )
  {
    victim->start_busy(1);
    message_vision("[1;33m$N成功的将$n的攻势反转过去 ![0m\n", me, victim);
  }
  else
  {
    message_vision("[1;32m$N错过了反击良机!![0m\n", me, victim);
  }
}

