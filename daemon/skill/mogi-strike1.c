// 血溶掌 by roger
// 这是魔界mob 的专用skill之一
#include <ansi.h>
#include <combat.h>
inherit SKILL;

void blood(object me, object victim, object  weapon, int damage);

string *parry_msg= ({
   "$n双手往上一翻, 双脚蹲了个马步, 使出一招「妖魔聚鼎”, 将妖气凝聚于全身上下, 硬生生的把$N的招式接了下来!\n",
   "$n伸出右手拇指, 食指, 中指, 使出一招「群妖拦路”, 三指由中宫飞快的探向$N的咽喉, 破解了$N的攻势。\n",
});

mapping *action = ({
([ "action" : HIR"$N伸手虚拍一掌，使出"HIM"‘"HIR"血溶掌"HIM"’"HIR"中的"HIM"‘"HIR"泣血攻心"HIM"’"HIR"$n立时脸色一变，胸中气血翻腾，口中鲜血狂吐!!\n"NOR,
        "dodge":   -30,
        "parry":   -20,
        "damage":   220,
        "force":    270,
        "post_action":  (:blood:),
        "damage_type" : "气血失调"
        
]),

([ "action" :HIR"$N双掌猛推，一招"HIM"‘"HIR"血溶掌"HIM"’"HIR"中的"HIM"‘"HIR"漫天血影"HIM"’"HIR"使出来只见$N的双掌喷出稠血浓雾，$n被笼罩其中只觉功力快速流失\n"NOR,
        "dodge":   -30,
        "parry":   -10,
        "damage":   210,
        "force":    270,
        "damage_type" : "血雾之毒"
]),

([ "action" : HIR"$N大喝一声，一掌"HIM"‘"HIR"血气逼人"HIM"’"HIR"掌风中挟着浓浓血雾气势骇人地往$n的胸口狂轰而去\n"NOR,
        "dodge":   -30,
        "parry":    20,
        "damage":   230,
        "force":    270,
        "damage_type" : "瘀伤"
]),

([ "action" : HIR"$N使出"HIM"‘"HIR"血溶掌"HIM"’"HIR"中的"HIM"‘"HIR"煞血一指"HIM"’"HIR"，指力千斤直往$n的胸口直刺而去，只见一条笔直的血箭由$n的胸口射出...\n"NOR,
        "dodge":    -30,
        "parry":    -20,
        "damage":   220,
        "force":    270,
        "damage_type" : "刺伤"
]),

([ "action" :HIR"$N内息一转，使出"HIM"‘"HIR"血溶掌"HIM"’"HIR"中的阴狠招数"HIM"‘"HIR"纯阴血气"HIM"’"HIR"四周忽然气温急降，鬼哭神号声音此起彼落，使的$n不禁吓得面如土色!!传说中此招者不但周身血脉被封，更日日被恶魂缠身不的安宁!!\n"NOR,
        "dodge":   -20,
        "parry":   -10,
        "damage":   190,
        "force":    250,
        "damage_type" : "心智受损"
]),

([ "action" :HIR"$N往$n的$l一抓，使出了"HIM"‘"HIR"血溶掌"HIM"’"HIR"中人人闻之色变的"HIM"‘"HIR"凝血神抓"HIM"’，"HIR"中此招者将于几天内气血滞行而死!!\n"NOR,
        "dodge":   -30,
        "parry":   -10,
        "damage":   200,
        "force":    250,
        "damage_type" : "抓伤"
]),

});

void blood(object me, object victim, object  weapon, int damage)
{

 victim->apply_condition("ff_poison",2);
}
int valid_enable(string usage)
{
        return (usage=="unarmed")||(usage=="parry");
}


mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

string query_parry_msg(string limb)
{
    return parry_msg[random(sizeof(parry_msg))];
}
