// sha-steps.c by Roger 5/24/98
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
"\n但是$n使出飞仙御剑步中的"HIW"「翦云身法”"NOR"，轻飘飘地早已退在几步之外\n",
"\n$n使出了飞仙御剑步中的"HIR"‘御剑乱诀’"NOR"，身影残幻，使$N的攻击招式全部落空\n",
"\n$n使出"HIB"‘倒踩七星步’"NOR"往后连退数步使$N的攻击全部落空，连$n的衣服都没沾到\n",
"\n$n使出了绝顶的"HIG"‘御剑草上飞’"NOR"，轻巧地避过了$N的这记杀招\n",
"\n但$n使出"HIC"‘踏水无痕’"NOR"轻功，毫无困难地闪过了这招\n",
"\n但$n使出"HIM"‘过眼身烟’"NOR"身法，使$N只攻击到$n残留的幻影\n",
});

int valid_skill_usage(string usage)
{
	return (usage=="dodge") || (usage=="move");
}
 int valid_enable(string usage)
 {
        return( usage=="dodge" || usage=="move") ;
 }

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 10 )
		return notify_fail("你的内力不够，没有办法练飞仙御剑步 .\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 20
	||	(int)me->query("force") < 5 )
		return notify_fail("你的气或内力不够，不能练飞仙御剑步 .\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
