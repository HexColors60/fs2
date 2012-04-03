// snow-kee.c
// 雪苍派的护身气劲..Chan Design
//
#include <ansi.h>
inherit SKILL;

string *parry_msg = ({
   HIC"$n雪苍护身内劲爆发,强大的寒劲硬生生将$N的攻势震开。\n"NOR,
   HIW"$n一手「"HIY"盘天式"HIW"”一手「"HIG"卧地式"HIW"”其势无穷无尽，将身旁守的固若金汤。\n"NOR,
   WHT"$n运脚如飞形成龙卷气劲，在身前织成一道紧密气网，将$N的猛烈攻势尽数卸开。\n"NOR,
   HIC"$n内力狂转，双手急挥使出雪苍武学之「"HIM"深渊势"HIC"”，$N的攻势如泥牛入海尽被$n气劲宣泄出去。 \n"NOR,
   HIW"$n使出雪苍护身寒劲之终极绝招【"HIC"--冰--风--雪--暴--"HIW"】\n"
   HIW"$n如同狂风暴冷般冰寒的气劲,使温度降至冰点,让$N攻势完全失去了效用\n"NOR,
            });

int valid_enable(string usage)
{
int family;
object me=this_player();
if ( me->query("family/family_name") == "雪苍派")
 return (usage=="parry");
else
 return notify_fail("只有雪苍门人才能用雪苍护身寒劲!!\n");
}

string query_parry_msg(string limb)
{
  int parry_pow;
  object me=this_player();
  if(!me) return parry_msg[random(sizeof(parry_msg))];
  parry_pow = (int)(me->query_skill("snow-kee", 1)/10);
  if ( parry_pow <= 8)
   return parry_msg[random(4)];
  else
   return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
if(me->query_skill("snowforce",1) < 60 )
   return notify_fail("你的雪苍内劲不够纯熟!!无法修习雪苍护身寒劲。\n");
  return 1;
}


int practice_skill(object me)
{
        if((int)me->query("kee")<100)
                return notify_fail("你的气不够，不能练雪苍护身寒劲。\n");
        me->receive_wound("kee",10);
        return 1;
}

    string perform_action_file(string action)
{
           return CLASS_D("fighter")+"/snow-kee/"+action;
}
