//pd-staff.c editer.by Chan

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void attack1(object me,object victim,object weapon,int damage);
void attack2(object me,object victim,object weapon,int damage);
void attack3(object me,object victim,object weapon,int damage);
void attack4(object me,object victim,object weapon,int damage);
void again1(object me,object victim,object weapon,int damage);
string *array_msg=
    ({
      "[1;33m$N带领着大家，形化四象，复化八卦使打狗阵法发挥致极点。\n[0m",
      "[1;33m众人发挥出阵法之奥妙变化，使敌人陷入绝望的深渊。\n[0m",
      "[1;33m$N指挥若定，众人武功配合的天衣无缝，将招式递向敌人。\n[0m",
      "[1;33m众人发挥出阵法之无穷奥义，将对敌人的损害发挥出最大的境界\n[0m",
     });
mapping *action = ({
(["action":"$N将手中的棒子,急晃数下使出"HIW"「棒打双犬”"NOR",对准$n的$l「倏”一声~击下",
"dodge":-60,
"parry":90,
"force":60,
"damage":60,
"damage_type" : "瘀伤",
]),
(["action":"$N使出"HIW"「棒打恶犬”"NOR",手中的棒子似有似无般的向$n的$l剌出",
"dodge":-60,
"parry":90,
"force":70,
"damage":70,
"damage_type" : "刺伤",
]),
(["action":"$N将手上的棒子,看拙实巧直直剌向$n的$l正是一招"HIW"「若隐若现”"NOR,
"dodge":-90,
"parry":110,
"force":100,
"damage":70,
"damage_type" : "剌伤",
]),
(["action":"$N跃至半空中,高举手中的棒子一招"HIW"「流星坠地”"NOR"，如流星般向$n的$l急劈而下",
"dodge":-90,
"parry":110,
"force":100,
"damage":80,
"damage_type" : "割伤",
]),
(["action":"$N将手中的棒子,急划圈圈一招"HIW"「无穷无尽”"NOR"，棒上的内劲向$n的$l袭去",
"dodge":-90,
"parry":110,
"force":100,
"damage":70,
"damage_type" : "内伤",
]),
(["action":"$N面对$n的攻击使出"HIW"「封狗在外”"NOR"，将攻击一封,利用棒子向$n的$l一剌",
"dodge":-90,
"parry":120,
"force":100,
"damage":80,
"damage_type" : "瘀伤",
]),
(["action":"$N将手中的棒子,由下往上挑起一招"HIC"「挑狗在天”"NOR"使$n被挑至空中并从旁向$l击出",
"dodge":-100,
"parry":120,
"force":100,
"damage":80,
"damage_type" : "瘀伤",
]),
(["action":"$N将内劲贯注至棒子,"HIC"「狂风追雪”"NOR"，棒劲所形成的寒风向$n的$l袭去",
"dodge":-100,
"parry":130,
"force":100,
"damage":85,
"damage_type" : "冻伤",
]),
(["action":"$N鼓尽全身内力,一招"HIC"「乱棒狂击”"NOR"，手中的棒子向$n的$l乱击而出",
"dodge":-100,
"parry":120,
"force":100,
"damage":90,
"damage_type" : "击伤",
]),
(["action":"$N狂吼一声,内力散发使出绝技"HIC"「天下无狗”"NOR"，漫天的棒势向$n的$l狂袭而去",
"dodge":-100,
"parry":120,
"force":110,
"damage":95,
"damage_type" : "刺伤",
]),
(["action":"$N领悟打狗棒法四大精义之"HIC"「乱”"NOR"字诀，手中的棒子其势无穷无尽般向$n的$l狂扫而去",
"dodge":-100,
"parry":120,
"force":110,
"damage":100,
"post_action":  (: attack1 :),
"damage_type" : "剌伤",
]),
(["action":"$N领悟打狗棒法四大精义之"HIC"「封”"NOR"字诀，手中的棒子如海天一线般封住$n的攻势,手肘同时击去",
"dodge":-100,
"parry":120,
"force":110,
"damage":100,
"post_action":  (: attack2 :),
"damage_type" : "瘀伤",
]),
(["action":"$N领悟打狗棒法四大精义之"HIC"「劈”"NOR"字诀，手中的棒子如闪电般从上向$n的$l狂劈而下",
"dodge":-100,
"parry":110,
"force":110,
"damage":105,
"post_action":  (: attack3 :),
"damage_type" : "砍伤",
]),
(["action":"$N领悟打狗棒法四大精义之"HIC"「引”"NOR"字诀，手中的棒子如青蛇出洞般向$n的$l狂剌而出",
"dodge":-100,
"parry":120,
"force":110,
"damage":105,
"post_action":  (: attack4 :),
"damage_type" : "剌伤",
]),
(["action":HIR"$N将谷尽全身的内力,使出打狗棒法中的‘乱击棒法’无数棒影铺天盖地般向$n袭去"NOR,
"dodge":-110,
"parry":150,
"force":150,
"damage":70,
"post_action":  (: again1 :),
"damage_type" : "瘀伤",
]),
});

mapping query_action(object me, object weapon)
{
int skill;
   skill=me->query_skill("pd-staff", 1);
   if( me->query_temp("use_form",1))
     message_vision( array_msg[random(sizeof(array_msg))],me );
   if( skill < 50)
      return action[random(7)];
   else if( skill < 60)
      return action[random(7)+2];
   else if( skill < 70)
      return action[random(7)+3];
   else if( skill < 80)
      return action[random(7)+5];
   else if( skill < 90)
      return action[random(7)+7];
   else
      return action[random(7)+8];
}
void attack1(object me, object victim, object weapon, int damage)
{
 int att_value,skill;
 skill=me->query_skill("pd-staff", 1);
 att_value = skill * 12;
 if((me->query_skill_mapped("force")=="siseforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIR"$N将打狗棒法结合洗髓经中的暗劲震伤$n全身血脉\n"NOR,me,victim);
   victim->add("force",-att_value);
   COMBAT_D->report_status(victim, 1);
  }
}
void attack2(object me, object victim, object weapon, int damage)
{
 int busy_value,skill;
 skill=me->query_skill("pd-staff", 1);
// busy_value = skill / 2;
 if((me->query_skill_mapped("force")=="siseforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIW"$N将打狗棒法中封字诀和降龙劲配合封住$n的四肢百骸\n"NOR,me,victim);
   victim->start_busy( 1 );
   COMBAT_D->report_status(victim, 1);
  }
}
void attack3(object me, object victim, object weapon, int damage)
{
 int att_value,skill;
 skill=me->query_skill("pd-staff", 1);
 att_value = skill * 14;
 if((me->query_skill_mapped("force")=="siseforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIB"$N将打狗棒法中转字诀注入降龙劲形成龙卷风袭向$n\n"NOR,me,victim);
   victim->add("kee",-att_value);
   COMBAT_D->report_status(victim, 1);
  }
}
void attack4(object me, object victim, object weapon, int damage)
{
 int att_value,skill;
 skill=me->query_skill("pd-staff", 1);
 att_value = skill * 14;
 if((me->query_skill_mapped("force")=="siseforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIG"$N将降龙劲配合打狗棒法的引字诀,其无穷的气劲剌伤$n\n"NOR,me,victim);
   victim->add("kee",-att_value);
   COMBAT_D->report_status(victim, 1);
  }
}

void again1(object me, object victim, object weapon, int damage)
{
        int i,time;
        int level=(int)(me->query_skill("pd-staff",1)/10);
	time=level+2;
        if (level > 6)
        {
  if( me->query_temp("pd-staff") == 0 && me->query("class")=="beggar" )
          {
              me->set_temp("pd-staff",1);
              message_vision(HIW"$N使出打狗棒法之「乱取之技”,无数的棒影向$n狂扫而去。\n"NOR, me, victim);
              for(i=1;i<=time;i++)
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
              me->delete_temp("pd-staff");
             me->start_busy(1);
          }
        } 

}

int practice_skill(object me)
{
  if ((int) me->query("max_force")<10000)
  return notify_fail("你武学知识不足，无法参透打狗棒法的精妙之处\n");
}

string perform_action_file(string action)
{
          return CLASS_D("beggar")+"/pd-staff/"+action;
}
int valid_learn(object me)
    {
        object weapon = me->query_temp("weapon");
        if( me->query("max_force") < 1000 ) {
            tell_object(me, "你的内力修为不够, 最少要有一千点。\n");
            return 0;
        }
        if(!(me->query("class") == "beggar")) {
            tell_object(me, "只有丐帮弟子才能学打狗棒法。\n");
            return 0;
        }
        if( me->query("str") >= 20 ) {
            tell_object(me, "你的臂力过大无法学打狗棒法。\n");
            return 0;
        }
        if(!(me->query("beggar/quests 10") == 1 )) {
            tell_object(me, "丐帮弟子要完成任务十才能学。\n");
            return 0;
        }
        if( me->query("force") < 500 ) {
            tell_object(me, "你目前的内力不到五百点, 无法练此绝学。\n");
            return 0;
        }
        if( (me->query("potential") - me->query("learned_points")) < 2 ) {
            tell_object(me, "你的潜能不到二点, 无法练此绝学。\n");
            return 0;
        }
        if( !weapon || weapon->query("skill_type") != "staff" ) {
            tell_object(me, "手中无棒怎么个练法呀?\n");
            return 0;
        }

        tell_object(me, "学此绝学需扣潜能二点。\n");
        me->add("potential", -2);
        return 1;
}
int valid_enable(string usage)
{        return ( usage=="staff" )||(usage=="parry");
}
