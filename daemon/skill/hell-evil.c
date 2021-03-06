// 地狱血劫手 by roger
// 这是魔界mob 的专用skill之一
#include <ansi.h>
#include <combat.h>
inherit SKILL;
string bleed();

string *parry_msg= ({
   "$N双手往上一翻, 双脚蹲了个马步, 使出一招「  妖魔聚鼎  ”, 将妖气凝聚于全身上下, 硬生生的把$n的招式接了下来!\n",
   "$N伸出右手拇指, 食指, 中指, 使出一招「  群妖拦路  ”, 三指由中宫飞快的探向$n的咽喉, 破解了$n的攻势。\n",
});

mapping *action = ({
([ "action" : "$N身子半伏, 倏的跃了起来, 从空中使出一招「  魑魅魍魉  ”, 右爪迅速的从$n头顶上抓了下来!\n"NOR,
        "dodge":   -30,
        "parry":   -20,
        "damage":   180,
        "force":    250,
        "damage_type" : "脸部抓伤",
]),

([ "action" : "$N双爪向内一抱, 身子后拱, 一式「魔性狂发”, 纵身向$n跃了过去, 双爪外分, 朝$n的脖子击了下去!\n"NOR,
        "dodge":   -30,
        "parry":   -10,
        "damage":   180,
        "force":    250,
        "damage_type" : "脖子扭伤",
]),

([ "action" : "$N加快起脚步, 使出一招「妖遁魔现”, 绕着$n急速旋转着, 忽然间似有千万只手爪向$n袭击而来, 分击$N身上各个不同要害。\n"NOR,
        "dodge":   -30,
        "parry":    20,
        "damage":   190,
        "force":    250,
        "damage_type" : HIR"伤口溃烂"NOR,
]),

([ "action" : "$N一招「群魔乱舞”使出, 只见残光乱影, $N的影子充斥着$n的眼帘之中, 浑不知$N会从何处发动攻击, 忽然$N一跃身, 已绕到$n身后, 向$n脑后击了下去。\n"NOR,
        "dodge":    -10,
        "parry":    10,
        "damage":   200,
        "force":    250,
        "damage_type" : HIR"头破血流"NOR,
]),

([ "action" : "$N左爪内弯, 右爪上提, 脚底游走着, 正是一式「  妖助魔势气更焰  ”, 左爪击向$n的天灵盖\上, 跟着又向右边略移半步, 提起右爪攻向$n的左肩。\n"NOR,
        "dodge":   -20,
        "parry":   -10,
        "damage":   190,
        "force":    250,
        "damage_type" : "破体之伤",
]),

([ "action" : "$N爪成刀掌, 一招「  炼狱妖斩手  ”使将出来, 横劈直砍的攻向$n的面, 手, 胸, 腹, 足等各个部位, 左脚爪则是一式「  帝魔横扫腿  ”横扫$n的下盘。\n"NOR,
        "dodge":   -30,
        "parry":   -10,
        "damage":   200,
        "force":    250,
        "damage_type" : "诡异刀伤",
]),

([ "action" : "$N挥舞着双爪, 一招「  天魔盗明珠  ”窜了出来, 双爪直逼$n中宫下盘二处, $n显得难以应付, $N右爪攻势忽的一转, 改为直取$n双目, 逼的$n步步后退。\n"NOR,
        "dodge":   -35,
        "parry":   -20,
        "damage":   180,
        "force":    240,
        "damage_type" : HIR"暂时失明"NOR,
]),

([ "action" : HIB"$N忽然停止一切攻击, 只是静静的凝视着$n, 这正是一招「  魔影幻攻心  ”, $n渐渐的感到口干舌燥, 心里面有如千万条虫蚁咬锲着, 麻痒难当。\n"NOR,
        "dodge":   -40,
        "parry":   -20,
        "damage":   190,
        "force":    250,
        "damage_type" : HIW"无影之伤"NOR,
]),

([ "action" : HIW"$N提气大喝一声! 使出一招「  恶妖探路	”急攻$n胸前, 接着又是一招「  小鬼拜阎王  ”直取$n右肩臂膀, 此二式来势汹"+"涌, 令人防不胜防, 忽的$N招式一变, 右爪使「  无影魔幻掌  ”左爪主「  七煞火焰掌  ”, 掌风飘移不定, 分别攻向$n的"+"头顶及背部,
 下盘则是踩着「  魔十二宫禁步  ”, 不断的向$n踢去, 瞬间五式变化, , 眼见$n以难以躲避了。\n"NOR,
        "dodge":   -15,
        "parry":   -10,
        "damage":   180,
        "force":    250,
        "damage_type" : HIR"大量失血"NOR,
]),
});

// can enable

int valid_enable(string usage)
{
        return (usage=="unarmed")||(usage=="parry");
}

// action message

mapping query_action(object me, object weapon)
{
        object *enemy, vim;
        int i, j, gin, kee, sen;

        if(random(10) > 8) {
           enemy = me->query_enemy();
           j = random(sizeof(enemy));
           vim = enemy[j];
           message_vision("$N的身上发出一股魔风，瞬时间$n的状态已经大不如前了\n",me,vim);
           gin = vim->query("eff_gin");
           kee = vim->query("eff_kee");
           sen = vim->query("eff_sen");

           vim->receive_damage("gin", gin/15);
           vim->receive_damage("kee", kee/15);
           vim->receive_damage("sen", sen/15);
           me->add("force", (int) -me->query("force")/20);
           COMBAT_D->report_status(vim, 1);
        }
       return action[random(sizeof(action))];
}


string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}
