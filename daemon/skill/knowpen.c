#include <combat.h>
#include <ansi.h>
inherit SKILL;

void special_attact1(object me, object victim, object weapon, int damage);
void special_attact2(object me, object victim, object weapon, int damage);
void sp_att1(object me, object victim, object weapon, int damage);
void sp_att2(object me, object victim, object weapon, int damage);
void sp_att3(object me, object victim, object weapon, int damage);
mapping *action = ({
      ([
        "action"     :
"$N手中$w一翻，一招"HIW"‘"NOR"行云流"HIB"水"HIW"’"NOR"手里的$w如一条长龙流转，往$n$l刺去",
        "dodge"      :               -10,
        "parry"      :               -10,
        "damage"     :                50,
        "force"      :                100,
        "damage_type":  "刺伤",
      ]),
      ([
        "action"     :
"$N身形流转，连踩七步，手中$w一招"HIW"‘"HIG"七步成"HIC"诗"HIW"’"NOR"往$n点去",
        "dodge"      :                0,
        "parry"      :                0,
        "damage"     :                50,
        "force"      :                100,
        "damage_type":  "刺伤",
      ]),
      ([
        "action"     :
"$N手中$w摇晃，步法微顿，倏地一招"HIW"‘"HIW"把"HIR"酒"NOR"问天"HIW"’"NOR"将$w挥出，连出三下往$n点去",
        "dodge"      :                -10,
        "parry"      :                10,
        "damage"     :                100,
        "force"      :                200,
        "damage_type":  "刺伤",
      ]),
      ([
        "action"     :
"$N将手里的$w高高举起，忽地手中$w急变招数，一招"HIW"‘"HIY"菊"HIM"园尽兴"HIW"’"NOR"连绵不绝的往$n急点",
        "dodge"      :                -20,
        "parry"      :                20,
        "damage"     :                100,
        "force"      :                200,
        "damage_type": "刺伤",
      ]),
///////////////////////// Below Add By AceLan ////////////////////////////////
      ([
        "action"     :
"$N忽然歪歪斜斜的走了两步, 使出一招"HIW"‘"HIR"拗步斜行"HIW"’"NOR",朝$n$l攻去",
        "dodge"      :                -30,
        "parry"      :                30,
        "damage"     :                150,
        "force"      :                250,
        "damage_type": "刺伤",
      ]),
      ([
        "action"     :
"$N看准了$n来势, 使出一招"HIW"‘"NOR"迎门"HIB"铁"HIR"扇"HIW"’"NOR", 潇洒的还了一击",
        "dodge"      :                -30,
        "parry"      :                20,
        "damage"     :                150,
        "force"      :                250,
        "damage_type": "刺伤",
      ]),
      ([
        "action"     :
"$N大喝一声, 身形急转, 使出儒门的绝招"HIW"‘"HIB"翻"HIR"花"HIY"舞"HIG"袖"HIW"’"NOR", 手里$w如雨点般朝$n洒落",
        "dodge"      :                -50,
        "parry"      :                40,
        "damage"     :                200,
        "force"      :                300,
        "damage_type": "刺伤",
      ]),
      ([
        "action"     :
"$N凝聚内力, 身旁瞬时刮起强风, 这正是儒门的"HIW"‘"HIB"风"NOR"扫"HIR"梅花"HIW"’"NOR", 只见$N的身影满天飞舞",
        "parry"      :                30,
        "dodge"      :                -40,
        "damage"     :                200,
        "force"      :                300,
        "damage_type": "刺伤",
      ]),
      ([
        "action"     :
"$N使出一招"HIW"‘"HIB"魁星"HIM"点"NOR"斗"HIW"’"NOR", 只见$N手中$w忽快忽慢忽左忽右地朝$n身上急点",
        "parry"      :                30,
        "dodge"      :                -40,
        "damage"     :                250,
        "force"      :                 300,
        "damage_type": "刺伤",
      ]),
           ([        "action":
"$N慢慢将真气运行全身带动四周气流，缓缓收起$w，准备使出儒门镇教绝式之一\n"
"$N的真气突然慢慢消失，掌力顺时降至三分，$n只有点招架不住。",
           "damage":        300,
           "dodge":        -30,
           "parry":         10,
           "post_action":  (: sp_att2 :),
              "damage_type":"瘀伤"
             ]),
           ([         "action":
"$N将握$w换成拿剑之态，忽地手中幻化成剑，准备使出儒教镇教绝式之一\n"
"$N因无法掌握住诱困杀灭四项剑意，$n似乎有点看穿破招之法。",
           "damage":        300,
           "dodge":        -30,
           "parry":         10,
           "post_action":  (: sp_att3 :),
              "damage_type":"割伤"
            ]),
      ([
        "action"     :
"$N身形急转, 突然凌空跃起, 手中$w左翻右翻, 朝$n身上指指点点, 急点而至,
这一招正是儒门的绝招"HIW"‘"NOR"转"HIB"龙"HIG"回"HIR"日"HIW"’"NOR,
        "dodge"      :                50,
        "parry"      :                30,
        "damage"     :                250,
        "force"      :                300,
        "damage_type": "刺伤",
        "post_action": (: special_attact1 :),
      ]),
      ([
        "action"     :
"$N身形突然拔高数丈, 使出一招"HIW"‘"HIB"云"HIR"开"HIY"龙"HIB"腾"HIW"’"NOR", 手中$w从空中飘然下划,
只见一道无形劲气, 挟着狂风朝着$n激射而至",
        "dodge"      :                60,
        "parry"      :                40,
        "damage"     :                300,
        "force"      :                300,
        "damage_type": "刺伤",
        "post_action": (: special_attact2 :),
      ]),
      ([
        "action"     :
"$N突然全身充满绿光，两眼电射出迫人的寒气，使出儒门至高笔法"HIW"‘"HIB"灵"HIR"龙"HIY"笔"HIB"书"HIW"’"NOR",
只见一道劲气挟着万丈光芒已将$n全身笼罩住了",
        "dodge"      :                60,
        "parry"      :                40,
        "damage"     :                300,
        "force"      :                300,
        "damage_type": "刺伤",
        "post_action": (: sp_att1 :),
      ]),

});

void special_attact1(object me, object victim, object weapon, int damage)
{
   int dam=victim->query("max_kee")/5;
   if( dam > 1000) dam= 1000;
   if(50>random(100))
   {
      message_vision(HIB
"\n$N手中"HIW+ weapon->query("name")+HIB"电光火石般连连颤动, 自$n灵台穴一路顺势而下, \n", me, victim);
      message_vision(
"使的是儒门的行云流水笔法中最凌厉的绝招, 在$n督脉的每一穴道都点上了一下。\n"NOR, me, victim);
      victim->receive_damage("kee", dam);
      COMBAT_D->report_status(victim, 1);
   }
   else
   {
      message_vision(HIB
"\n$N手中"HIW+ weapon->query("name")+HIB"电光火石般连连颤动, 自$n灵台穴一路顺势而下, \n"NOR, me, victim);
      message_vision(HIW
"不过$n身形更快, 巧妙的避过了$N的这致命的一击\n"NOR, me, victim);
   }
}

void special_attact2(object me, object victim, object weapon, int damage)
{
   int dam=victim->query("max_kee")/5;
   if( dam > 1000) dam= 1000;
   if(50>random(100))
   {
      message_vision(HIB
"\n$N使出看家本领, 顿时狂风大作, 手中"HIW+ weapon->query("name")+HIB"幻化出阵阵刚气, \n", me, victim);
      message_vision(
"忽左忽右, 似慢实快, 似轻实重地朝$n狂劈而来。\n"NOR, me, victim);
      victim->receive_damage("kee", dam);
      COMBAT_D->report_status(victim, 1);
   }
   else
   {
      message_vision(HIB
"\n$N使出看家本领, 顿时狂风大作, 手中"HIW+ weapon->query("name")+HIB"幻化出阵阵刚气, \n", me, victim);
      message_vision(
"忽左忽右, 似慢实快, 似轻实重地朝$n狂劈而来。\n"NOR, me, victim);
      message_vision(HIW
"不过$n身形更快, 巧妙的避过了$N的这致命的一击\n"NOR, me, victim);
   }
}

// valid_learn 只是检查是否可以学, 不能在此加 skill
int valid_learn(object me)
{
   if ((int)me->query_skill("literate")*2<(int)me->query_skill("knowpen"))
      return notify_fail("你的读书识字程度不够，不能领悟其中的道理。\n");
   return 1;
}

void sp_att1(object me, object victim, object weapon, int damage)
{
   int dam=victim->query("max_kee")/5;
   if( dam > 1000) dam= 1000;
   if( 50>random(100))
   {
      if( present("ten pen", me))
      {
         dam/=3;
         message_vision(
""HIW"$N口里默唸：‘笔锋流转，遍体寒光，冷苍之月，冻化成芒’"NOR"\n"
""HIW"$N潜运诗易心法，脚踏冬霜冰雪步法，手里灵龙天笔顿时发出阵阵刚气。"NOR"\n"
""HIW"只见四周空气结成阵阵寒霜，朝$n激射而至，射穿了$n的护体真气，造成重创"NOR"\n",me,victim);
      }
      else
      {
         dam/=5;
         message_vision(
""HIW"$N随意挥撒手中$w，只见阵阵刚气朝$n激射而出"NOR"\n",me,victim);
      }
       victim->receive_daemage("kee", dam);
       COMBAT_D->report_status(victim, 1);
       me->add("force",-100);
   }
}

void sp_att2(object me, object victim, object weapon, int damage)
{
   int dam=victim->query("max_kee")/5;
   if( dam > 1000) dam= 1000;
   if(50>random(100))
   {
      message_vision(
""HIW"$N再缓缓将真气运转入任督二脉，顺时真气充盈于全身之中，使出儒门镇教秘招"NOR"\n"
""HIW"               ‘～儒～教～极～招～"HIC"君"HIW"～"HIC"子"HIW"～"HIC"风"HIW"～’"NOR"\n"
""HIW"$N真气随掌而去，并带动四周气流击向$n，$n如失线之风筝受创飞起。"NOR"\n",me,victim);
         victim->receive_daemage("kee", dam);
         COMBAT_D->report_status(victim, 1);
         me->add("force",-100);
   }
}
void sp_att3(object me, object victim, object weapon, int damage)
{
   int dam=victim->query("max_kee")/5;
   if( dam > 1000) dam= 1000;
   if(50>random(100))
   {
      int i;
      for(i=1;i<=4;i++)
      {
         message_vision(HIW"你握起手中之诸凤剑笔，以笔代剑，顺时点破绝式精妙之处，十分流畅的使出剑招！\n"NOR,me,victim);
         switch(i)
         {
            case 1:
                message_vision(sprintf("$N使出‘"HIC"剑～影～诱～敌"NOR"’，以无数虚招迷惑$n。\n"),me,victim);
                break;
            case 2:
                message_vision(sprintf("$N使出‘"HIC"剑～势～困～敌"NOR"’，以无数剑势困住$n。\n"),me,victim);
                break;
            case 3:
                message_vision(sprintf("$N使出‘"HIC"剑～招～杀～敌"NOR"’，以无数剑招杀向$n。\n"),me,victim);
                break;
            case 4:
                message_vision(sprintf("$N使出‘"HIC"剑～锋～灭～敌"NOR"’，以锋利剑锋杀灭$n。\n"),me,victim);
                break;
         }
           victim->receive_daemage("kee",dam);
           COMBAT_D->report_status(victim, 1);
      }
      me->add("force",-100);
   }
}

int valid_enable(string usage)
{
   return (usage=="stabber")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
// skill level < 40 只能使用前 9 招
if( me->query_skill("knowpen",1) < 40)
      return action[ random( sizeof( action)- 4)];
// skill level > 50 不使用前 4 招...增加特攻使用率...
   else
      return action[ random( sizeof( action)- 4)+ 4];
}

// 这个只是查询是否可以练习, 增加 skill 不是在这儿.
int practice_skill(object me)
{
   object weapon;

   me->receive_damage("sen",30);
   if (me->query_skill("literate")*2<me->query_skill("knowpen"))
      return notify_fail("你的读书识字不够，不能领悟其中的道理。\n");
   if( !objectp(weapon = me->query_temp("weapon")) ||
      ( string)weapon->query("skill_type")!="stabber")
   {
      return notify_fail("你要有适合的武器才能练行云流水笔法。\n");
   }

   if( ( int)me->query("sen")<30)
      return notify_fail("你的神不够，不能练行云流水笔法。\n");
   return 1;
}

string perform_action_file(string action)
{
   return CLASS_D("scholar")+"/knowpen/"+action;
}
