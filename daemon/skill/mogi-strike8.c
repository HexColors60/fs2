// mogi npc skill 之 太阴虚幻宝鉴
#include <ansi.h>
#include <combat.h>
inherit SKILL;
string *parry_msg= ({
   "$n双手往上一翻, 双脚蹲了个马步, 使出一招「妖魔聚鼎”, 将妖气凝聚于全身上下, 硬生生的把$N的招式接了下来!\n",
   "$n伸出右手拇指, 食指, 中指, 使出一招「群妖拦路”, 三指由中宫飞快的探向$n的咽喉, 破解了$N的攻势。\n",
});

mapping *action = ({
([ "action" : HIC"$N身影翩翩使出太阴虚幻宝鉴中的一式"HIY"‘蝶舞花山’"HIC"，如风摇尘飘忽不定地接近$n，出奇不意地点向$n$l\n"NOR,
        "dodge":   20,
        "parry":   20,
        "damage":  250,
        "force":   290,        
        "damage_type" : "刺伤"
        
]),

([ "action" :HIC"$N双足轻踮使出一式"HIY"‘雀舞稻香’"HIC"犹如雀鸟点跃，轻盈而迅速地向$n$l点去"NOR,
        "dodge":   30,
        "parry":   30,
        "damage":   250,
        "force":    270,
        
        "damage_type" : "刺伤"
]),

([ "action" :HIC"$N飞如轻风流荡回旋，一式"HIY"‘凤舞瑶池’"HIC"漫天飞舞盘绕，以幻为真以虚为实地划向$n\n"NOR,
        "dodge":   30,
        "parry":    30,
        "damage":   250,
        "force":    290,
        "damage_type" : "割伤"
]),

([ "action" :HIC"$N飞身翻跃使出太阴虚幻宝鉴中的一式"HIY"‘龙舞云端’"HIC"，在眨眼间转柔为刚聚力于指，笔直朝$n$l刺去\n"NOR,
        "dodge":    30,
        "parry":    30,
        "damage":   270,
        "force":    300,
        "damage_type" : "刺伤"
]),

([ "action" :HIC"$N倩影尽散，魅光氤氲，一式"HIY"‘魅舞月下’"HIC"化出妖影万千，仿佛群魔挣血群群围向$n\n"NOR,
        "dodge":   100,
        "parry":   100,
        "damage":  240,
        "force":   270,
        
        "damage_type" : "阴伤"
]),

([ "action" :HIC"$N一式"HIY"‘女舞穹苍’"HIC"在举手投足之间散着阵阵香气，如仙女回夜游魂走尘，若隐若现地刺向$n心窝\n"NOR,
        "dodge":   100,
        "parry":   100,
        "damage":  240,
        "force":   270,       
        "damage_type" : "阴伤"
]),

});

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
