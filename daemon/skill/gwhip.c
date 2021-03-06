// coding by ken 
// fix by borstquc
// Chan重新QC 08/27/98 之前威力强了点.改弱..
//fix by airke
#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void hurt(object me, object victim, object weapon, int damage);
void bleed(object me, object victim, object weapon, int damage);
void conti(object me, object victim, object weapon, int damage);

string pit();

string *parry_msg = ({
        "而$n不慌不忙，虚招一递，一式"HIW"‘"HIB"画龙点睛"HIW"’"NOR"直取$N双眼，$N一惊之下赶紧撤招回架!\n",
	"$n遇招拆招"HIW"‘"HIY"斗转星移"HIW"’"NOR"使的得心应手，已将$N的攻势卸的毫无威力可言。\n",
        "$n手中拂尘一扬，以四两拨千金手法拨开了$N的攻击\n",
        "$n借力打力，劲力一发，将$N的去势卸得偏了准头\n",
	"但$n见状，反以一招"HIW"‘"MAG"蟠龙锁关"HIW"’"NOR"对准$w来势紧紧锁住，拂尘往后一扬$N的$w被扯的险些脱手而出!!\n",
        });

string query_parry_msg(string limb)
{
      
        return parry_msg[random(sizeof(parry_msg))] ;
      
}

mapping *action = ({
        ([      "action":               "$N使出一招「龙尾刺”，手中$w如针般刺向$n的$l",
                "dodge":                -10,
                "damage":               20,
                "damage_type":  "刺伤",
                
        ]),
        
        ([      "action":               "一招「峰回路转”，$N手中$w如一条银蛇般缠向$n的$l",
                "dodge":                -20,
                 "damage":               25,
                "damage_type": "刺伤",
                   
        ]),

        ([      "action":               "$N手上$w灵动而出，一招「龙尾甩”，手中$w疾劈$n的$l",
                "dodge":                -20,
                "damage":                35,
                "damage_type":  "割伤",
                
        ]),

        ([      "action":               "$N手中$w向中宫直进，一式「旭日东升”对准$n的$l刺出",
                "parry":                -20,
                "dodge":                -10,
                "damage":                40,
                "damage_type":  "刺伤",
                
        ]),

        ([      "action":               "$N纵身一跃手中$w内劲澎湃，「"HIY"巨龙盖\顶"NOR"”对准$n上路直直压下",
                "dodge":                -30,
                "force":                60,
                "damage":               50,
                "damage_type":  "割伤",
                
        ]),

        ([      "action":               "$N两手往前一送$w螺旋甩出，一招「"HIG"毒龙钻"NOR"”直刺$n的$l",
                "parry":                -10,
                "dodge":                -20,
                "force":                 40,
                "damage":                60,
                "damage_type":  "刺伤",
                
        ]),

        ([      "action":               "$N手中$w向外一分，使一招「"HIR"双龙噬"NOR"”，反手对准$n$l击去",
                "parry":                -25,
                "dodge":                -20,
                "force":                 40,
                "damage":                 70,
                "damage_type":  "刺伤",                
        ]),

        ([      "action":               "$N奋力使出一式「"HIM"御风而行"NOR"”，身形陡然滑出数尺，$w飘然而出，柔中带刚直指$n的$l",
                "dodge":                -10,
		"force":		40,
                     "damage":                75,
                "damage_type":  "割伤",
               
        ]),
        
        ([      "action":               "$N脚踏七星步身形一快，一招「"HIW"金虹断空"NOR"”$w隔空划出一道弧光闪电般斩向$n",
                "parry":                -20,
                "dodge":                -25,
                "damage":	         80,
                "damage_type":  "割伤",
        
        ]),

        ([      "action":               "$N一招「"HIC"天道击"NOR"”，手中$w疾风暴雨地点向$n$l",
                "parry":                -20,
                "force":                 60,
                "damage":                75,
                "damage_type":  "刺伤",
                
        ]),

        ([      "action":               "$N清啸一声，内力疾吐一式「"HIB"雷厉风行"NOR"”，$w以迅雷之势向$n拂去",
                "dodge":                -30,
                "force":                 60,
                "damage":                80,
                "damage_type":  "瘀伤",
        ]),

        ([      "action":               "$N手中$w舞开，「"MAG"盘龙错"NOR"”一闪而出，有如盘龙出谷威不可赫，一瞬间将$n$l缠得咯咯作响",
                "dodge":               -25,
		"force":                40,
                "damage":                80,
                "damage_type":  "瘀伤",
                
        ]),
});



int valid_learn(object me)
{
        object ob;

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "whip" )
                write("你必须先装备武器才能练鞭法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="whip" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
     int whipski=me->query_skill("whip");   
     if( whipski < 40 )
         return action[random(4)];
     if( whipski < 60 )
         return action[random(7)];
     if( whipski < 80 )
         return action[random(7)+4];
     
     return action[random(8)+4];
}

int practice_skill(object me)
{
        me->receive_damage("kee", 10);
        me->add("force", -15);
        write("你按着所学练了一遍紫龙鞭法。\n");
        return 1;
}

string skill_improved(string me)
{
         tell_object(this_player(),"你的鞭法苦练有成，变得比以前更加灵活。\n");
}
string perform_action_file(string action)
{
        return CLASS_D("taoist") + "/gwhip/" + action;
}
