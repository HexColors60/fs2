// gather.c
#include <combat.h>
#include <ansi.h>
inherit SSERVER;
int kee_out(object me,object target)
{
int msk=me->query("max_s_kee",1);
if(msk > 500) msk=500;
     if(me->query("s_kee")<10)
      {
          tell_object(me,"你的灵气不够。\n");
          return 1;
      }
        if(me->query("class") != "marksman")
        {
         tell_object(me,"你不是射手根本无法驾御心中之火凰灵气!!!\n");
                return 1;
        }

 if(!me->is_fighting())
  return notify_fail("火凰灵气战斗中才能使用!!!。\n");
 if(!target->is_fighting())
  return notify_fail("对方并不是在处于战斗之中，所以无法使用火凰灵气!!!\n");
 if(target->query_temp("phoenix")==2) {
 tell_object(me,"敌人已被火凤灵气缠绕，无法在动了。\n");
 return 1; }
      message_vision(
         HIC + "$N口中缓缓唸出一串真言，只见一只火凤凰迅速破空降下！\n" NOR,me);
         message_vision(  HIR "火凤凰迅速飞向$n，并隐入$N的体内。\n" NOR,me,target);
        target->receive_damage("kee",me->query("max_atman")/5);
        target->start_busy(1);
        target->add_temp("phoenix",1);
        target->apply_condition("phoenix_out",me->query("max_s_kee")/10);
      COMBAT_D->report_status(target);
      me->add("s_kee",-10);
      me->kill_ob(target);
        return 1;
}
