
// fole-ken.c //风雷八式// write by ｃｃｈ..

inherit SKILL;
#include <ansi.h>
mapping *action = ({
([	"action":"$N狂吼一声,上空平身挪后三寸,左手拍地,右手股动内劲,一招"HIW"‘气临山河动’"+NOR",破天而出,
掌劲如山,激起无涛的气劲,夹着雷霆万驹之势朝$n而来!!",
	        "dodge":		-10,
		"parry":		-40,
		"force":		200,
		"damage":               135,
		"damage_type":	"瘀伤"
	]),
([	"action": "$N使出一招"HIW"‘雷鼓震山川’"+NOR",力与神会,劲由意生,一鼓雄浑的内劲.起自足底,
顺劲推出,连暴声声巨响,完全发挥"HIC"‘一川碎石大如斗’"+NOR"之精义,$n劲风佛面,
已处万劫险境,虎虎的劲风击向$n胸口!!",
		"dodge":		-40,
		"parry":		-10,
		"force":		270,
		"damage":               150,
		"damage_type":	"震伤"
	]),
([	"action": "$N使出风雷八式"CYN"‘水精势绝伦’"+NOR",双掌猛扬,一片青色的劲气,尤如万丈飞瀑,
夹着一股排山倒海的掌风,冲向$n身前,怒海洪涛般的击向$n..",
		"dodge":		-15,
		"parry":		-20,
		"force":		120,
		"damage":               60,
		"damage_type":	"劈伤"
	]),
([	"action": "$N左足横移,挫腰沈身,单袖一扬使出"YEL"‘风沙暗夜吼’"+NOR",瞬时狂风拂起, 
尘沙飞扬,乃武诀之"HIY"‘平沙莽莽黄入天,随风满地石乱走’"+NOR"$N趁飞沙走石之际,
朝$n的天灵盖\连续出数掌!!",
		"dodge":		-50,
		"parry":		-25,
		"force":		160,
		"damage":               110,
		"damage_type":	"瘀伤"
	]),
([	"action": "$N运起阳刚真气,天灵聚起一片炙火,身形一旋,双掌内拢,使出"HIR"‘火光燎天戈’"+NOR",一圈,
一吐,催起一股凌厉的气焰,扫向$n!!",
		"dodge":		-30,
		"parry":		-10,
		"force":		100,
		"damage":               60,
		"damage_type":  "烫伤"
	]),
([	"action": "$N双掌飘飘,连递数十掌,领悟武诀中之"HIW"‘长风吹林雨坠瓦’"+NOR",
此乃风雷八式之"HIC"‘雨凝破山石’"NOR",掌影弥漫,看似狂风暴雨,
掌气有如细雨般同时洒向$n全身要穴!!",
		"dodge":		-10,
		"parry":		-30,
		"force":		150,
		"damage":               70,
		"damage_type":	"侵蚀之伤"
	]),
([	"action": "$N揉身而上,飘然滑行,顺势使出"HIW"‘电花照天河’"+NOR",双掌如刀如剑,挥动之际,
泛起一片光芒,有如电光之势,$n顿时眼前罩上一片炙光,一阵昏眩,
光刀迅速的朝$n各部位砍去!!",
                "dodge":                -35,
		"parry":		 20,
  		"force":		120,
		"damage":                80,
		"damage_type":	"破体之伤"
	]),
([      "action": "$N运起寒冰真气,不觉体泛冰气,瞬间.....卷起一阵寒风,此时双掌疾吐,
施展一招"HIC"‘冰寒囓人心’"+NOR",煞时寒气从掌心飘出,$n已被寒气逼的步法错乱,
刺骨冰寒的掌气,不断的往$n各处拍去!!!",
                "dodge":               -10,
                "parry":               -40,
                "force":               130,
                "damage":              100,	
                "damage type":  "冻体之伤"
        ]),        
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("风雷八式是掌法..必须放下兵刃。\n");

	if( (int)me->query("max_force") < 200 )
		return notify_fail("你的内力太弱,硬练会导致经脉破裂.\n");
	return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的体力不够,不能再练了。\n");
	if( (int)me->query("force") < 5 )
		return notify_fail("你没有足够的内力一展绝学.\n");
	me->receive_damage("kee", 20);
	me->add("force", -5);
    write("你提起真气将绝式练了一遍,顿时觉得功力又更上一层楼. \n"); 
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
 if( damage_bonus < 100 ) return 0;
  if( random(damage_bonus/2) > victim->query_str() ) {
    victim->receive_wound("kee", (damage_bonus - 100) / 2 );
        switch(random(3)) {
        case 0: return "$N的掌气扎实的击中,$n连退数十步,并吐了一口鲜血!!\n";
        case 1: return "$N劲力一吐，$n的身体发出「喀”地一声爆响,似乎骨头以被击碎.\n";
        case 2: return "一声惨叫,$n的以被击中,$n已面含惊惧之色,神情惨然.\n";
              }}}
              
