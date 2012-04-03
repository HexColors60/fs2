#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
int perform(object me, object target)
{
int value,k_level,unit=1,i,hart=150;
  int other;
  string msg;
  object ob,victim = target;
  string *name;
  if( !target ) target = offensive_target(me);
  if(!target) return notify_fail("你找不到敌人!!\n");
  if((me->query_skill("snow-martial",1) < 50) || (me->query_skill("snowforce",1)<60) )
   return notify_fail("你的雪苍武学及雪苍心法不够纯熟，无法聚气凝霜。\n");
  if( (string)me->query_skill_mapped("force")!= "snowforce")
   return notify_fail("雪影幻指必须使用雪苍心法才能发挥威力。\n");
  if( me->query("family/family_name") != "雪苍派" )
   return notify_fail("雪影幻指只有雪苍派的门人才可以使用。\n");

  if(!(ob=me->query_temp("weapon")))
  {
   if(me->query_temp("secondary_weapon"))
    return notify_fail("寒气被手上的武器给阻止了!!\n");}
   if(ob=me->query_temp("weapon"))
    {
     if((string)ob->query("skill_type") != "unarmed")
      return   notify_fail("不空手怎么使用幻指!!\n");
    }
   if(me->query("force")<500)
     return notify_fail("你的内力不够。\n");
   if(me->query("kee")<200)
     return notify_fail("你的气不够。\n");
   if(!me->is_fighting(target))
    {
     tell_object(me,"雪影幻指只能在战斗中才能使用。\n");
     return 0;
     }
   value = me->query("functions/ice-fingers/level");
   if ( value < 10 ) value = 10;
   if ( value > 50 ) value = 50;
   value = value / 10;
   for (i=0;i<value;i++)
    {
      switch (i)
      {
       case 0:
        message_vision(HIW"$N使出雪影幻指之「"NOR""CYN"雪影憧憧"HIW"”,漫天指影、无数寒光向$n狂飙而至。\n"NOR, me, target);
        break;
       case 1:
        message_vision(HIW"$N使出雪影幻指之「"CYN"雪苍漫漫"HIW"”,漫天掌势、无数寒劲向$n狂袭而至。\n"NOR, me, target);
        break;
       case 2:
        message_vision(HIW"$N使出雪影幻指之「"HIB"大雪漫天"HIW"”,浑厚寒劲、无尽掌影向$n狂攻而至。\n"NOR, me, target);
        break;
       case 3:
        message_vision(HIW"$N使出雪影幻指之「"HIM"雪梅绽放"HIW"”,掌如梅花、凌厉寒势向$n狂扫而至。\n"NOR, me, target);
        break;
        case 4:
        message_vision(HIW"$N使出雪幻奥义之「"RED"暴雪急袭"HIW"”,无穷掌影、无尽掌势向$n狂击而至。\n"NOR, me, target);
        break;
      }
// 修正全数命中 by swy
        message_vision(MAG"$n被$N的雪影幻指准确的命中要穴,$n身上己留下青紫色的指痕\n"NOR, me, target);
        target->receive_damage("kee",hart);
        target->apply_condition("cold",random(15)+1);
        me->add("force",-40);
        COMBAT_D->report_status(target);
        hart = hart + (int)me->query("max_force")/100;
    }
    message_vision(HIR"$N使出雪影幻指后!!内劲损耗过大，无法移动。\n"NOR,me);
    me->start_busy(1);
    COMBAT_D->report_status(target, 1);

if(me->query("functions/ice-fingers/level") < 100)
{
function_improved("ice-fingers",random(me->query("max_force")/15+
me->query_skill("snow-martial")));
}
    message_vision( NOR,me);
    return 1;
}

