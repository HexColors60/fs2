// blood_magic.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage=="magic"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("magic") < (int)me->query_skill("blood_magic")/2 )
                return notify_fail("你的法术修为不够，无法领悟更高深的血魔咒。\n");
        return 1;
}

string conjure_magic_file(string magic)
{
        return CLASS_D("swordsman") + "/blood_magic/" + magic;
}
int conjure_magic (object me, string magic, object target)
{
	if( file_size(conjure_magic_file(magic)+".c") > 0 )
	return conjure_magic_file (magic)->conjure(me,target);
	return notify_fail("没有这样法术。\n");
}

