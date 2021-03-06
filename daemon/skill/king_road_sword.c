// KING_ROAD_SWORD.c
#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void sp_attack0(object me, object victim, object  weapon, int damage);
int kar=this_player()->query("kar",1);
int cps=this_player()->query("cps",1);
int str=this_player()->query("str",1);
int cor=this_player()->query("cor",1);
int int1=this_player()->query("int",1);
int spi=this_player()->query("spi",1);
mapping *action = ({
	([	"action":		
HIW"$N将真气灌注于$w"HIC"，剑身本身剑灵与真气激荡，缓缓发出共鸣之声

                        "HIY"王者之路"HIW"之「"HIR"秋末悲歌"HIW"”

"HIW"共鸣之声渐渐转变为阵阵亡者悲鸣之声，$n渐渐受悲鸣之声所扰！",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                300,
                "force"      :                300,
                "damage_type":               "刺伤"
	]),
	([	"action":		
HIW"$N将剑气随意而发，剑气在真气流转之间化为阴阳剑气，剑气形成日月双形

                         "HIY"王者之路"HIW"之「"HIR"日"HIY"月"HIC"同天"HIW"”

"HIW"日月剑气一刚一柔互相弥补，日月剑气渐化太极之势毫无破绽，击向$n！",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                350,
                "force"      :                350,
                "damage_type":               "刺伤"
	]),
	([	"action":		
HIW"$N心神突然受剑招影响，心性渐渐转为狂暴，剑随心行，剑招渐渐越舞越狂

                          "HIY"王者之路"HIW"之「"WHT"搏命"HIW"”

"HIW"剑招狂乱中带有逼杀之意，$n无法看清$N疯狂剑舞中之破绽！",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                400,
                "force"      :                400,
                "damage_type":               "刺伤"
	]),
	([	"action":		
HIW"$N真气突然如海翻腾，剑气也随着真气如波涛一般，只见剑气化为一道道剑浪

                          "HIY"王者之路"HIW"之「"HIB"欲望之海"HIW"”

"HIW"剑浪在$n四周突然汇流，瞬间形成一道无形漩涡迅捷的将$n卷入其中！",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                450,
                "force"      :                450,
                "damage_type":               "刺伤"
	]),
	([	"action":		
HIW"$N真气渐转阴柔，剑气随真气渐渐转化成一阴柔剑气，如丝如絮，飘缈难寻

                           "HIY"王者之路"HIW"之「"HIM"无怨无尤"HIW"”

"HIW"剑气在与$n接触的一瞬间，剑气由$l透体窜入，进入$n经脉之中！",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                500,
                "force"      :                500,
                "damage_type":               "刺伤"
	]),
	([	"action":		
HIW"$N真气于丹田中运转，运转中真气越运越加激烈，剑招在无意中变得刚烈

                           "HIY"王者之路"HIW"之「"HIG"庐山不动一剑痕"HIW"”

"HIW"剑势之猛如同狂龙啸天，$n如惊弓之鸟临时想不出应对之策",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                550,
                "force"      :                550,
                "damage_type":               "刺伤"
	]),
	([	"action":		
HIW"$N缓唸一段剑诀「"HIR"指天为名"HIW"、"WHT"拄地为功/"HIW"、"HIM"忘弃红尘"HIW"”，随后身形急旋而上

                           "HIY"王者之路"HIW"之「"HIM"忘弃红尘"HIW"”

"HIW"幻化出无数身影后，剑气四散而出，$n瞬时被剑气笼罩",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                340,
                "force"      :                340,
                "damage_type":               "刺伤"
	]),
});
int valid_enable(string usage)
{
        return (usage=="sword")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

