// 金风细雨楼skill 之 盘古开天刀法
//第一楼楼主刁千刃武功
#include <combat.h>
#include <ansi.h>
inherit SKILL;
mapping *action = ({
	([	"action":		"$N收刀聚气，蓄势待发，空气逐渐凝结，就在$n步入刀界的瞬间$N一式"HIR"‘劈天破日’"NOR"浑厚的刀气激烈地向$n拂扫而去",
		"damage":	600,
                "force":        600,
                "damage_type" : "砍伤"
	]),
	([	"action":		"$N双握$w，单足踮步拔身数丈以高制低，一式"HIY"‘剖天断月’"NOR"凝重了空气，刀光如弧月划天直直朝$n落下",
		"damage":	600,
                "force":        600,
                "damage_type" : "砍伤"	
	]),
	([	"action":		"$N拔足飞身使出一式"HIC"‘擎天挟宇’"NOR"朝$n追去，激起碎天刀气随风而扬急追$n",
		"damage":	600,
                "force":        600,
                "damage_type" : "砍伤"	
	]),
	([	"action":		"$N御气飞刀，一式"HIW"‘吞天推谷’"NOR"手里$w已回绕至$n背后，如迅雷一瞬，人刀错位，却在眨眼间刀已回鞘",
		"damage":	600,
                "force":        600,
                "damage_type" : "劈伤"		
	]),
        ([      "action":              "$N贯力一式"HIC"‘盘古开天刀法’"NOR"中的"HIC"‘划天落命’"NOR"，迅速地向前挥刀而去，猛烈的力道将$n震浮飞空，瞬间反手倏上，刀光直突上天",
		"damage":	600,
                "force":        600,
                "damage_type" : "劈伤"             
        ]),
});



int valid_enable(string usage)
{
        return usage=="blade" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

