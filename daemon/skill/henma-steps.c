// henma-steps.c
#include <ansi.h>
inherit SKILL;

string *dodge_msg = 
({
      
      "$n使出"MAG"「幻灭岚影”"NOR"，右足轻点，回身反转，"HIG"‘湖静风迎漪涟生’"NOR"，身行一滑开\n这正是"HIG"‘烟柳绿满风飘絮  新月如钩映江舟’"NOR"，无声无息的闪避$N的狂风暴雨般的攻击。\n",
      "$n蹈出"MAG"「幻灭岚影”"NOR"，足下斜行，身不点地，"HIY"‘逢按磬钟楼宇空’"NOR"，腾空飞跃而起\n若如是"HIY"‘越城莫作万里客  天外共斟千杯酒’"NOR"，消失于迷雾中，使的$N完全无法下手。\n",
      "$n斜踩"MAG"「幻灭岚影”"NOR"，似实似虚，跃空滑开，"HIG"‘江上无波清风徐’"NOR"，纵向跃开来\n原正是"HIG"‘霞影划过天际云  山岚迭涌青山行’"NOR"，瞬间从$N的身旁，斜斜缓缓的绕了过去。\n",
      "$n反踏"MAG"「幻灭岚影”"NOR"，身化数影，虚实难分，"HIG"‘回拾春意暖寒湮’"NOR"，斜向远远滑去\n此吟做"HIG"‘古来青山不见忧  空惟江水去悠悠’"NOR"，身形忽尔凌空一提，轻轻柔柔的飘了开去! \n",
      "$n悟出"MAG"「幻灭岚影”"NOR"，足踏身起，翩然闪隐，"HIY"‘行路花落雨缤纷’"NOR"，身形顿失踪迹\n语吟曰"HIY"‘俯仰天地浮云子  徘恛美景空飘流’"NOR"，身体微微倾侧，使$N的力道轻柔的卸了去！",

});

int valid_enable(string usage) 
{
        return (usage=="dodge")||(usage=="move");
}

string query_dodge_msg(string limb)
{
  int dodge_pow;
  object me=this_player();

  if(!me) return dodge_msg[random(sizeof(dodge_msg))];
        dodge_pow = (int)(me->query_skill("henma-steps", 1)/10);
        if ( dodge_pow <= 5)
              return dodge_msg[random(4)];
        else
              return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
        if(me->query ("combat_exp") <= (me->query_skill("linpo-steps",1)*6) )
          return notify_fail("你的战斗经验不足，无法体会幻灭岚影中精妙身法。\n");
        return 1;
}


int practice_skill(object me)
{
        if((int)me->query("kee")<5)
                return notify_fail("你的气不够，不能练幻灭岚影。\n");
        me->receive_wound("kee",5);
        return 1;
}

