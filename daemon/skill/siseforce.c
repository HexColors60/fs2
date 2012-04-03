//siseforce by Dico
//洗髓经

#include <ansi.h>
inherit SKILL;

int valid_enable(string usage) { return usage=="force"; }

string exert_function_file(string func)
{
	return CLASS_D("beggar")+"/siseforce/"+func;
}

void skill_improved(object me)
{
	int s;
	tell_object(me,HIW"你的脸色由青变红、红变青洗髓经的修为更进一步了。\n" NOR);
        s = me->query_skill("siseforce", 1);
        if( s%10==9 && random(s)>(int)me->query("max_force")/30) {
                tell_object(me, HIW "一股洗髓内劲从丹田发出散入全身，使你的内功修为提高了。\n" NOR);
                me->add("max_force", random((int)s/30)+1);
        }
}

string perform_action_file(string action)
{
	return CLASS_D("beggar")+"/siseforce/"+action;
}