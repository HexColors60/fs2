// follow-force by chan
#include <ansi.h>
inherit SKILL;

int valid_enable(string usage) { return usage=="force"; }

int practice_skill(object me)
{
        return notify_fail("莲花心经只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
        return CLASS_D("beggar") + "/followforce/" + func;
}
