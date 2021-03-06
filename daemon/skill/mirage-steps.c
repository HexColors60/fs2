// mirage-steps.c  //离影迷纵步// write by cch

inherit SKILL;
#include <ansi.h>
string *dodge_msg = ({
	"$n双袖一扬,"CYN".......一阵青烟从地底冒出........ "+NOR",
一招"HIC"‘烟雾弥三江’"+NOR",$n已不知去向,$N似忽陷入迷境,不知如何出招。\n",
	"只见$n身影一晃,腾空而起,使出"HIB"‘星垂暗影落’"+NOR",身驱有如星抛丸掷,
画出一条曼妙的圆弧,$n的招式早以落空。\n",
	"$n使出离影迷踪步之"HIY"‘凌风无形迹’"+NOR",身形如燕,身影随风幻化方位,
$N的招式始终差了三寸,潇洒的避过每一招。\n",
	"$n随意使出一招"HIG"‘翠影映波澜’"+NOR",左足一点,身形一闪,早以绕到$N身后。\n",
	"$n身影微动,脚踏醉仙望月步,正是一招"HIW"‘舞影醉人痴’"+NOR",身形飘缈虚幻,
穿梭在$N的攻势之下,$n竟仍留于原地。\n",
	"$n凌空飞起,使出一招"HIC"‘萦回荡秋波’"+NOR",拧身一折,忽左忽右的飘开,
$N招式未到,$n早以飘落三尺开外之处。\n",
        "$n顿时心无杂念,意随念转,眼看$N攻势逼进,口中喃喃自语,霎那间,一灵三化,
$N显然以分不出虚实,招招向残影击去. \n",  
      
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        if(me->query ("combat_exp") <= (me->query_skill("mirage-steps",1)*6) )
                return notify_fail("你的实战经验不足,无法体会步诀之精奥。\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够,无法练离影迷纵步。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 10 )  
             return notify_fail("你的气不够，不能练‘离影迷纵步’。\n");
        if( (int)me->query("force") < 30 )
             return notify_fail("你的内力不够，无法练‘离影迷纵步’。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
