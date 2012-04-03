#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
int sk;
void remove_effect (object me);
int perform(object me, object target)
{
sk=me->query_skill("paull-steps",1);
if (sk<80)
     return notify_fail ("妳的技能等级尚不足使用此技能!\n");
  if (me->query ("force") < 50)
     return notify_fail ("妳的内力不足!\n");
  if ((int)me->query_temp ("rainbow-steps", 1))
     return notify_fail ("妳已经使用七彩幻梦了。\n");
  if ( me->query("class") !="dancer" )
     return notify_fail ("妳不是舞者无法使用七彩幻梦。\n");

if( me->is_fighting() ) me->start_busy(1); //在战斗中使用,要busy自己一回合 by chan

  message_vision ("\n"HIW"$N"NOR"结合月影微步与夜梦天舞的精要纵身飞起使出终极舞步"HIM"「七彩幻梦”"NOR"\n",me,target);
  me->add ("force", -50);

       
  message_vision (HIG"刹时间$N整个人变的身轻如燕。\n"NOR, me,target);

// 设这个mark后就有dodge_sp 了
  me->set_temp ("rainbow-steps", 1);
   
  me->start_call_out((: call_other, __FILE__, "remove_effect",me:),sk*2);

  return 1;
}

void remove_effect (object me)
{
// 删除 manashield   
int fun=me->query("functions/rainbow-steps/level");
  me->delete_temp ("rainbow-steps");
  tell_object (me, NOR"妳觉得自己的身体沈重下来了。\n"NOR);
  if(fun<100) function_improved("rainbow-steps",random(500)+sk);   
  return;
}
