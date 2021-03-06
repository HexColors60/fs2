//绛雪神剑 by bss
#include <ansi.h>
#include <combat.h>

void berserk2(object me, object victim, object  weapon, int damage);
void sp1(object me, object victim, object  weapon, int damage);
void sp2(object me, object victim, object  weapon, int damage);
void sp3(object me, object victim, object  weapon, int damage);
//void sp4(object me, object victim, object  weapon, int damage);
string *parry_msg=({
        "$n手中$w忽然脱手一抖，正是一招"+HIY+"「剑流星”"+NOR+"，顷刻间剑如流星运转，巧绝无方，将$N的攻势尽数挡了下来。\n",
        "$n身躯一引, 手中$w将$N的攻势尽数曳了开去。\n",
        "$n把手中的$w舞成圆环, 将$N的攻势尽数挡了下来。\n",
        "$n以静制动, 平举手中$w, 无招胜有招, 化解了$N的攻势!\n",
        });

mapping *action = ({
        ([
                "action"     :
"$N施展出浣花剑派绝招"HIY"「倒飞剑”"NOR"，突然间转过身来，身形腾起，唰的一剑，
往$n胸前直刺，速度飞快，眼看$n就要中招了。",
                "dodge"      :                -500,
                "damage"     :                750,
                "damage_type":               "刺伤",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
        ]),
        ([
                "action"     :
"$N剑作刀使，忽地一招"+HIY+"「龙啸九天”"+NOR+", 手中$w由下而上的砍向$n，因砍削空气所形成得螺漩气流如狂风般攻向$n。",
                "dodge"      :                -500,
                "damage"     :                145,
                "damage_type":               "砍伤",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp1:),
        ]),
        ([
                "action"     :
"$N忽然将手中$w藏于背后，正是一招"+HIB+"「无剑势”"+NOR+",正当$n搞不清楚状况的时后，$w\n忽然由$N的腰旁刺出，刺向$n。",
                "dodge"      :               -500,
                "damage"     :                165,
                "damage_type":               "刺伤",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
        ]),
        ([
                "action"     :

"$N将$w抛向空中，$n见机不可失，迅速的向$N进攻,$N忽然眼放精光，跟着跃至空中接\n剑，顺势下劈，正是一招"+HIC+"「怒斩神州”"+NOR+" ，千万道剑气随着剑势攻向$n。",
                "dodge"      :                -500,
                "damage"     :                200,
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":                (: sp2 :),
                "damage_type":                "砍伤",
         ]),
         ([
                "action"     :
"$N忽然向前大跨一步，一股庞大的杀气从$N身上涌出，$N大喝一声"+HIR+"「杀龙求道”"+NOR+"，霍地旋身而起，剑随身转，旋风般朝$n猛攻。",
                "dodge"      :                -500,
                "damage"     :                220,
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "damage_type":                "割伤",
         ]),
         ([
                "action"     :
"$N将$w斜插于地，身形急转，大喝一声"+HIY+"「潜龙升天”"+NOR+"，手中$w带起了一阵上升气流，仿佛要将四周的一切全部卷到空中似的",
                "dodge"      :                -500,
                "damage"     :                350,
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp3:),
                "damage_type":                "割伤",
         ]),
         ([
                "action"     :
"$N手中$w急抖，$w的剑气有如鞭子一般卷向$n，剑气所带起的气流牢牢锁定着$n，正是能使剑有如使鞭的绝技\n"+
"            "+HIY+"   ～～～　剑     流     云  ～～～ "+NOR+"　　",
                "dodge"      :                -500,
                "damage"     :                550,
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp2:),
                "damage_type":                "割伤",

         ]),
        ([
                "action"     :
"只听$N如沉雷暴喝一声，人已箭步而上，顷刻间剑气暴放成万道剑光，浑然在半空中刺出一个斗大的"+HIY+"「剑”"+NOR+"字，铺天盖\地的向$n压去，正是能在虚空留痕的---- \n"+
"            "+HIC+"   ～～～　剑     流     痕  ～～～ "+NOR+"　　",
                "dodge"      :                -500,
                "damage"     :                800,
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp2:),
                "damage_type":               "刺伤",
        ]),
        ([
                "action"     :
"$N左手持剑，右手捏个剑诀，双手成环，缓缓抬起，这是[1;37m玄龙剑法绝式[0m的起手式。",
                "dodge"      :                -500,
                "damage"     :                700,
                "damage_type":               "刺伤",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:berserk2:),
        ]),
        ([
                "action"     :
"$N高举手中的$w，迅速地在身前虚空劈了一个很大的"+HIC+"八"+NOR+"字，正是圣灵剑法之"+HIR+"「剑八”"+NOR+"，剑气产生了很大的破空声，直向$n而去。",
                "dodge"      :                -500,
                "damage"     :                800,
                "damage_type":               "砍伤",
                "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp1:),
        ]),
        ([
                "action"     :
"$N施出「无名剑法”中的极致"+HIR+"「悲痛莫名”"+NOR+"，剑网交织的向$n攻去，使得$n不禁为了$N剑式中那悲伤的剑意所感动。",
                "dodge"      :                -500,
                "damage"     :                700,
                "damage_type":               "刺伤",
               "post_action":  (:call_other,__FILE__,"damage_weapon":),
                "post_action":  (:sp2:),
        ]),

});

mapping query_action(object me, object weapon)
{
   int skill_level, limit;
   skill_level = (int)(me->query_skill("bss-sword", 1));
   limit= (int)( skill_level/ 10);
      if (limit < 2 )
         return action[random(4 )];
      else if (limit < 3 )
         return action[random(5 )];
      else if (limit < 4 )
         return action[random(6 )];
      else if (limit < 5 )
         return action[random(7 )];
      else if (limit < 6 )
         return action[random(8 )];
      else if (limit < 7 )
         return action[random(9 )];
      else if (limit < 8 )
         return action[random(10 )];
         return action[random(11)];
}


void sp1(object me, object victim, object  weapon, int damage)
{
   int skill= me->query_skill("bss-sword", 1);
   message_vision("$N受到螺旋剑气的影响，脸上忽青忽白，看来是受到了内伤了\n",victim);
   victim->add("kee", -(skill* 3));
   victim->apply_condition("hart",random(5)+((int)me->query_skill("dragonsword",1)/5));
   COMBAT_D->report_status(victim, 1);
   victim->start_busy(1);
}
void sp2(object me, object victim, object  weapon, int damage)
{
   int skill = me->query_skill("bss-sword", 1);
   message_vision("$N的剑气在$n体内四处乱撞，造成严重的内伤\n",weapon,victim);
   victim->add("kee",-(skill* 3));
   victim->apply_condition("hart",random(5)+((int)me->query_skill("dragonsword",1)/5));
   COMBAT_D->report_status(victim, 1);
   victim->start_busy(1);
}
void sp3(object me, object victim, object  weapon, int damage)
{
   int skill = me->query_skill("bss-sword", 1);
   message_vision("$N被$n所带起的上升气流，卷至空中并被撕裂开来\n",victim,weapon);
   victim->add("kee",-(skill* 3));
   COMBAT_D->report_status(victim, 1);
   victim->start_busy(1);
}


void berserk2(object me, object victim, object  weapon, int damage)
{
 int skill_level=me->query_skill("bss-sword",1),bound;
 bound = victim->query("max_kee");
 bound = (bound/100)*5;
  if( random(170) > 27 && me->query("force",1) > 100 )
  {
    if(!me->query_temp("berserk2"))
    {
    if(weapon->query("id")=="dragon sword")
     {
       message_vision(
         sprintf(HIW"\n$N忽然眼放精光，大喝一声「风云连续剑”，刹那间四周涌起一道黑云，使$n完全失去$N的踪影!!\n\n"NOR),me ,victim);
       message_vision(
         sprintf(HIW"\n$N以传音之术对$n说到:「接招吧”，招式如狂风般朝$n袭至!!\n\n"NOR),me ,victim);
       message_vision(
 sprintf(HIW"\n风云连续剑第一式"HIB"‘行云流水’"HIW"，"HIY"神龙剑"HIW"有如流水般朝$n攻去，使人目不暇己\n"NOR),me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW"\n风云连续剑第二式"HIB"‘披星戴月’"HIW"，"HIY"神龙剑"HIW"忽然朝$n直刺过去，刺中了$n身上几大要穴\n"NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW"\n风云连续剑第三式"HIB"‘翻云覆雨’"HIW"，"HIY"神龙剑"HIW"如风车般在$N身旁转了起来，$n被剑招所产生的\n\n螺漩气流所侵，受了重伤\n"NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW"\n风云连续剑第四式"HIB"‘排山倒海’"HIW"，$N将"HIY"神龙剑"HIW"插入土地，跟着用力拔起，随"HIY"神龙剑"HIW"而飞起的土石\n\n击中了$n\n"NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW"\n风云连续剑第五式"HIB"‘重云深锁’"HIW"，$N用手中"HIY"神龙剑"HIW"在$n身上画了十几个小圆圈，$n\n\n忽然身体一震，动弹不得\n\n"NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
      message_vision(
 sprintf(HIW"\n风云连续剑第六式"HIB"‘风卷残楼’"HIW"，$N拔身而起，剑随身转，如一道龙卷风般朝$n攻去\n"NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW"\n风云连续剑第七式"HIB"‘狂风暴雨’"HIW"，剑招连绵不绝的朝$n攻去，使$n身受重创\n"NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW"\n风云连续剑第八式"HIB"‘神风怒嚎’"HIW"，"HIY"神龙剑"HIW"在空间中快速的砍劈，使四周产生了巨大的破空声\n"NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW"\n风云连续剑第九式"HIB"‘撕天排云’"HIW"，"HIY"神龙剑"HIW"迅速的向左右各劈了两下，剑气快速地攻向$n\n"NOR), me ,victim,weapon);
 victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW"\n风云连续剑第十式"HIB"‘云海波涛’"HIW"，剑气如巨浪狂涌而至，$n连闪避的机会也没有\n"NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
       message_vision(
 sprintf(HIW"\n风云连续剑第十一式"HIB"‘殃云天绛’"HIW"，$N跃至空中，手中"HIY"神龙剑"HIW"朝$n直劈而去，剑气充斥着这整个空间\n"NOR), me ,victim,weapon);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim, 1);
     message_vision(
 sprintf(HIW"\n$N使完剑法一十一式后，周围的黑云渐渐地消散了。\n\n"NOR), me ,victim);

}
}
}
}
int valid_learn(object me)
{
   object ob;
//   if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") !="sword")
//      return   notify_fail("少了把剑练起来怪不顺手的, 还是拿把剑再来练吧。\n");
   return   1;
}

int valid_enable(string usage)
{
   return ( usage=="sword") || ( usage=="parry" );
}

int practice_skill(object me)
{
  if( (int)me->query("kee") < 25 )
     return notify_fail("你的体力不够了，休息一下再练吧。\n");
  if( (int)me->query("gin") < 5 )
     return notify_fail("你的精力不够了，休息一下再练吧。\n");
  if( (int)me->query("force") < 1 )
     return notify_fail("你的内力不够了，休息一下再练吧。\n");
  me->receive_damage("kee", 25);
  me->receive_damage("gin", 5);
  me->add("force", -1);
  return 1;
}

string perform_action_file(string action)
{
   return CLASS_D("swordsman")+"/dragonsword/"+action;
}

string query_parry_msg(string limb)
{
   return parry_msg[ random( sizeof( parry_msg))];
}

void skill_improved(object me)
{
tell_object(me,"[1;34m由于你潜心学习，你的玄龙剑法更加纯熟了！！[0m\n");
}




