// security.c

inherit SKILL;

int valid_enable(string usage) { return usage=="be-officer"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
	return notify_fail("治安策只能用学的。\n");
}

string command_file(string name)
{
	return CLASS_D("officer")+"/security/"+name;
}

