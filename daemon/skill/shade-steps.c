// shade-steps.c

inherit SKILL;

string *dodge_msg = ({
    "$n身影微动,已经藉一招「[35m星光四散[0m”绕到$N四周形成四个幻影。\n",
    "$n身形一转使出「[35m红鸾星动[0m”瞬时人离原位而避了开去,$N击中了幻影。\n",
    "只见$n身影一晃即失,一式「[35m流星赶月[0m”已幻化在三丈之外。\n",
    "$n使出「[35m斗转星移[0m”,$N之攻势瞬间被化解,$n从容不迫地闪过。\n",
    "但$n使出一招「[35m星随气转[0m”,身子随$N攻击之气流轻轻飘了开去。\n",
    "$n身形微晃忽成七个幻影,$N困惑不已而攻击失误,正是一招「[35m幻化七星[0m”。\n",
     "$n人影忽灭,突见无数星芒环绕在$N周围,使$N目瞪口呆,不知所措,这正是 幻星步 精华步法-「[35m星罗棋布[0m”。\n",

});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if(me->query("kee") < 30 )
		return notify_fail("你的气不够，没办法练幻星步。\n");
	me->receive_damage("kee", 30);
	return 1;
}
