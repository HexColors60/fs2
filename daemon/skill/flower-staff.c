//pd-staff.c editer.by Chan

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void attack1(object me, object victim, object  weapon, int damage);
void again1(object me, object victim, object  weapon, int damage);
string *array_msg=
    ({
      "[1;33m$N带领着大家，形化四象，复化八卦使打狗阵法发挥致极点。\n[0m",
      "[1;33m众人发挥出阵法之奥妙变化，使敌人陷入绝望的深渊。\n[0m",
      "^[[1;33m$N指挥若定，众人武功配合的天衣无缝，将招式递向敌人。\n^[[0m",
      "[1;33m众人发挥出阵法之无穷奥义，将对敌人的损害发挥出最大的境界\n[0m",
     });
mapping *action = ({
(["action":"$N对准$n的弱点,狂挥而下使出"HIW"「力劈华山”"NOR",对准$n的$l部份击下",
"dodge":-60,
"parry":90,
"force":60,
"damage":50,
"damage_type" : "瘀伤",
]),
(["action":"$N看出$n的罩门使一招"HIW"「虎虎生风”"NOR",手中的棒子夹带强大的气劲向$n的$l挥出",
"dodge":-60,
"parry":90,
"force":70,
"damage":50,
"damage_type" : "瘀伤",
]),
(["action":"$N将手上的棒子,直直剌向$n的$l正是一招"HIW"「直攻而入”"NOR,
"dodge":-90,
"parry":110,
"force":100,
"damage":60,
"damage_type" : "剌伤",
]),
(["action":"$N跃至半空中,高举手中的棒子猛挥而下一招"HIW"「流星赶月”"NOR"，如流星般向$n的$l急劈而下",
"dodge":-90,
"parry":110,
"force":100,
"damage":70,
"damage_type" : "割伤",
]),
(["action":"$N将手中的棒子,急划反转使出莲花杖法之奥义"HIW"「无尽无悔”"NOR"，漫天的棒影向$n的$l袭去",
"dodge":-90,
"parry":110,
"force":100,
"damage":80,
"post_action":  (: again1 :),
"damage_type" : "内伤",
]),
(["action":"$N面对$n唱出莲花落之"HIW"「乞讨余羹”"NOR"，将$n的攻击一封",
"dodge":-90,
"parry":120,
"force":100,
"damage":90,
"post_action":  (: attack1 :),
"damage_type" : "瘀伤",
]),
(["action":"$N以敌不动,我不动面对$n以一招奥义"HIC"「莲花无影”"NOR"使$n被挑至空中并从旁向$l击出",
"dodge":-100,
"parry":120,
"force":100,
"damage":90,
"damage_type" : "瘀伤",
]),
(["action":"$N逆运真气,幻化无形莲花奥义"HIC"「狂风怒吼”"NOR"，棒劲所形成的风劲向$n的$l袭去",
"dodge":-100,
"parry":130,
"force":100,
"damage":90,
"damage_type" : "瘀伤",
]),
});

mapping query_action(object me, object weapon)
{
int skill;
   skill=me->query_skill("follow-staff", 1);
   if( me->query_temp("use_form",1))
     message_vision( array_msg[random(sizeof(array_msg))],me );
   if( skill < 50)
      return action[random(4)];
   else if( skill < 60)
      return action[random(4)+1];
   else if( skill < 70)
      return action[random(4)+2];
   else if( skill < 90)
      return action[random(4)+3];
   else
      return action[random(4)+4];
}
void attack1(object me, object victim, object weapon, int damage)
{
 int busy_value,skill;
 skill=me->query_skill("follow-staff", 1);
 busy_value = skill / 3;
 if((me->query_skill_mapped("force")=="followforce")&&(me->query("force_factor") >= 1 ))
  {
   message_vision(HIY"$N将莲花杖法结合和莲法心法发出气丝封住$n的四肢百骸\n"NOR,me,victim);
   victim->start_busy( busy_value );
   COMBAT_D->report_status(victim, 1);
  }
}

void again1(object me, object victim, object weapon, int damage)
{
 int i,value,k=0,skill,l=5;
 skill=me->query_skill("follow-staff", 1);
 skill = skill / 10;
 if(skill > 9)
 {
  k = 6;
  l = 3;
 }
 else if (skill > 7)
      {
       k = 5;
       l = 4;
      }else if (skill > 4 )
       {
        k = 4;
        l = 5;
       }
 if(me->query("force")>100&&me->query("force_factor"))
 {
   for (i=0;i<k;i++)
    {

      message_vision(HIW"$N使出莲花棒法之「乱击之技”,无数的杖影向$n狂扫而去。\n"NOR, me, victim);
      value = random (10);
      if (value >= l)
       {
        message_vision("结果被$N准确的命中要害,$n身上留下深厚的棒痕。\n", me, victim);
        victim->receive_wound("kee",25,me);
        me->add("force",-50);
        COMBAT_D->report_status(victim, 1);
       }
      else
        message_vision("结果$n在漫天的棒影穿了出来。\n", me, victim);
    }
    message_vision(HIW"一阵狂扫之后，$N内劲损耗过大，无法移动。\n"NOR,me);
    me->start_busy(1);
    COMBAT_D->report_status(victim, 1);
  }
}

int practice_skill(object me)
{
  if( (int)me->query("kee") < 30 )
      return  notify_fail("你的气不够，无法练习莲花杖法。\n");
  if( (int)me->query("force") < 5 )
      return  notify_fail("你的内力不够，不能练习莲花杖法。\n");
  me->receive_damage("kee", 30);
  me->add("force", -5);
  return 1;
}

string perform_action_file(string action)
{
          return CLASS_D("beggar")+"/follow-staff/"+action;
}
int valid_learn(object me)
    {
        object weapon = me->query_temp("weapon");
        if( me->query("max_force") < 50 ) {
            tell_object(me, "你的内力修为不够, 最少要有五十点。\n");
            return 0;
        }
        if(!(me->query("class") == "beggar")) {
            tell_object(me, "只有丐帮弟子才能学莲花杖法。\n");
            return 0;
        }
        if( me->query("str") >= 20 ) {
            tell_object(me, "你的臂力过大无法学莲花杖法。\n");
            return 0;
        }
        if( !weapon || weapon->query("skill_type") != "staff" ) {
            tell_object(me, "手中无棒怎么个练法呀?\n");
            return 0;
        }
        return 1;
}
int valid_enable(string usage)
{        return ( usage=="staff" )||(usage=="parry");
}
