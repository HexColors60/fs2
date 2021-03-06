// spring-blade.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N手中$w腾出，使出一式「浩气万千”往$n$l劈去",
		"damage":		200,
	"dodge":		50,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N一招「气若干云”，手中$w如猛虎般往$n$l砍去",
		"damage":	150,
		"dodge":	-20,
		"parry":	40,
		"damage_type": "砍伤",
	]),
	([	"action":		"$N高举手中$w，一招「万夫莫敌”往$n$l劈去",
		"damage":	200,
		"dodge":	40,
		"parry":	30,
		"damage_type": "砍伤",
	]),
	([	"action":		"$N将手中$w一撩，一招「干戈玉帛”往$n$l砍去",
		"damge":	50,
		"dodge":	20,
		"parry":	10,
		"damage_type": "砍伤",
	]),
});

int valid_learn(object me)
{
	return 1;
}

int valid_enable(string usage)
{
	return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "blade" )
		return notify_fail("你必须先找一把刀，才能练刀法。\n");

	if( (int)me->query("kee") < 40 )
		return notify_fail("你的体力不够练这门刀法，还是先休息休息吧。\n");
	me->receive_damage("kee", 40);
	return 1;
}
