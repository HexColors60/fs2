#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
inherit F_CLEAN_UP;
int perform(object me, object target)
{
  int flv,value;
  int tim;

   if(me->query("force")<50+(int)query_function("snow-powerup")*7)
          return notify_fail("你的内力不够，不能使用凌霜奇劲诀。 \n");
   if( me->query("family/family_name") != "雪苍派" )
          return notify_fail("凌霜奇劲诀为雪苍派内传之技巧。\n");
   if( (string)me->query_skill_mapped("unarmed")!= "snow-martial")
          return notify_fail("凌霜奇劲诀必须配合雪苍武学。\n");
   if( (string)me->query_skill_mapped("parry")!= "snow-kee")
          return notify_fail("使用凌霜奇劲诀必须要有寒劲护体。\n");
   if(me->query("powerup_flag"))
          return notify_fail("你已经在用了。\n");
   flv=(int)me->query_skill("force")/5;
   if(flv>90) flv=90;
   value = (int)me->query("functions/snow-powerup/level");
   if ( value > 80 )
   { 
      message_vision(HIC"
		$N以全身寒气，逼使出凌霜奇劲之「无尽式”
	             "NOR""BWHT""HIW"●无＝－＝垠＝－＝霜＝－＝雪●"NOR""HIC"
      	    $N周身包围着寒气，劲力似乎如大河决提般不吐不快！\n"NOR,me);
	me->set("force_factor",flv);
if(!me->query("snow_add_force")) { 
me->add("force",me->query("max_force"));
me->set("snow_add_force",1); } 
    } else if ( value > 60 )
    {
     message_vision(
     HIW"$N运起凌霜奇劲之最高功力---"HIC"化霜成劲"HIW"---使你的掌上凝结一层寒霜。\n
         $N感觉手上的寒劲源源不断!!内力随之增强!!!\n" NOR,me);
     me->set("force_factor",flv);
    }else if ( value > 40 )
    {
     message_vision(
     HIW"$N运起凌霜奇劲第三层功力---"HIC"化雪成劲"HIW"---使你的掌上发出丝丝的雪气。\n
         $N感觉手上的雪气源源不断!!内力随之增强!!!\n" NOR,me);
      me->set("force_factor",flv);
    }else if ( value > 20 )
    {
     message_vision(
      HIW"$N运起凌霜奇劲之第二层功力---"HIC"化水成劲"HIW"---将你手中的水气凝结成冰魄。\n
         $N感觉手上的水劲源源不断!!内力随之增强!!!\n" NOR,me);
     me->set("force_factor",flv);
    }else
    {
     message_vision(
     HIW"$N运起凌霜奇劲之第一层功力---"HIC"化气成劲"HIW"---将丹田的内力凝结成力。\n
         $N感觉全身的内劲源源不断!!内力随之增强!!!\n" NOR,me);
     me->set("force_factor",flv);
    }
    me->add ("force", -250);
    me->set("powerup_flag",1);
    me->apply_condition("powerup",1+value/10);	
  return 1;
}

