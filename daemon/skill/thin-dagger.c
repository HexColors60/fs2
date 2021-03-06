//金风细雨楼skill 之 细诀匕法
//这是金风细雨楼一般护卫之skill
#include <combat.h>
#include <ansi.h>
inherit SKILL;
mapping *action = ({
	([	"action":		"$N一式‘细柳孔雀’蹲身捞上如雀冲翔，瞬滑而落反手再刃，又以极快的速度回锋向$n突进"NOR,
		"damage":	90,
                "force":        90,
                "damage_type" : "刺伤"
	]),
	([	"action":		"$N将身子压得极低向前急急踏步使出了‘细桂胧泉’，直向$n下盘叩击突进"NOR,
		"damage":	90,
                "force":        90,
                "damage_type" : "刺伤"	
	]),
	([	"action":		"$N从侧切入使出一式‘细樱天嶂’，$w如风乱樱瓣勾裂着空气朝$n连环切刺"NOR,
		"damage":	90,
                "force":        90,
                "damage_type" : "刺伤"	
	]),
	([	"action":		"$N如碎杏随风飘旋，翩然使出一式‘细杏飘舞’，忽左忽右的上下飘动，瞬间以极快的速度向$n划去"NOR,
		"damage":	90,
                "force":        90,
                "damage_type" : "刺伤"		
	]),
        ([      "action":              "$N使出一式‘细树参周’，在往$n$l扫砍的当儿回身再进，几乎在同一时间又朝$n脑喉心腹四处突入"NOR,
		"damage":	90,
                "force":        90,
                "damage_type" : "刺伤"             
        ]),
});



int valid_enable(string usage)
{
        return usage=="dagger" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

