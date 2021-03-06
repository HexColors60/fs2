// sword.c

inherit SKILL;

mapping *actions = ({
	([	"action":		"$N用手中的$w往$n$l斩去",
		"damage_type":	"割伤",
	]),
	([	"action":		"$N挥动$w，往$n$l砍去",
		"damage_type":	"斲伤",
	]),
	([	"action":		"$N将手中$w对准$n$l一剑刺去",
		"damage_type":	"刺伤",
	]),
	([	"action":		"$N挥动手中$w，削向$n$l",
		"damage_type":	"刺伤",
	]),
});

varargs mapping query_action()
{
   return actions[ random( sizeof( actions))];
}

string perform_action_file( string func)
{
   return PERFORM_D("sword/") + func;
}

