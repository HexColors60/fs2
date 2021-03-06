// snowforce.c

inherit SKILL;
inherit SSERVER;

void special_force_damage(object me, object victim, object weapon, int damage);

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

mapping *force_action = ({
([      "post_action": (: special_force_damage :) ])
});

int practice_skill(object me)
{
             return notify_fail("雪苍派内功只能用学的，或是从(exert)中获的熟练度。\n");
}

mapping query_action(object me, object weapon)
{
          return force_action[random(sizeof(force_action))];
}

string exert_function_file(string func)
{
        return CLASS_D("fighter")+"/snowforce/"+func;
}
string perform_action_file(string action)
{
return CLASS_D("fighter")+"/snowforce/"+action;
}
        
void special_force_damage(object me, object victim, object weapon, int damage)
{
//   object target;
//   target=offensive_target(me);
        if( me->query("force_factor") == 10
                && me->query("force") >= 10 && damage > 0 )
        {
                message_vision(
                "$N发出一股刚猛的内劲，把$n弹了出去。\n", me, victim);
                victim->add("kee", -1*me->query_skill("force")/4);
        }
}
