// axe.c

inherit SKILL;

mapping *actions = ({
    ([  "action":       "$N往前一劈，$w劈了过去",
        "damage_type":  "劈伤",
	]),
([  "action":       "$N寻着空隙，一个箭步上前手中$w便往$n$l砍去",
        "damage_type":  "砍伤",
	]),
    ([  "action":       "$N手中$w一转，劈向$n$l",
        "damage_type":  "劈伤",
	]),
    ([  "action":       "$N对准$n$l挥了过去",
        "damage_type":  "砍伤",
	]),
    ([  "action":       "$N反转手中$w，「唰”地一声往$n$l劈去",
        "damage_type":  "劈伤",
	]),
});

varargs mapping query_action()
{
   return actions[ random( sizeof( actions))];
}


