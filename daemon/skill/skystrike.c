
//by poloer
// sky-strike(灭天拳)

inherit SKILL;
inherit SSERVER;
#include <ansi.h>
#include <combat.h>
void burn(object me, object victim, object  weapon, int damage);

mapping *action = ({
        ([      "action":                "$N右手连拍数招虚招，左掌突然使出一招阴险无比的"HIR"‘丧尽天良’"NOR"化虚为实击向$n的$l",
                "parry":                 -60,
                "dodge":                 -60,
                "force":                 250,
                "damage":                280,
                "post_action":               (: burn :),
                "damage_type":   "瘀伤"
        ]),
        ([      "action":                "$N的左掌忽然反拍，掌式充满傲然气势突如其来地使出一招"HIM"‘天奈我何’"NOR"击向$n$l",
                "parry":                 -60,
                "dodge":                 -60,
                "force":                 250,
                "damage":                270,
                "post_action":               (: burn :),
                "damage_type":   "瘀伤"
        ]),
        ([      "action":                "$N将左手画圆右掌作方，跟着使出一招"HIC"‘无法无天’"NOR"，双掌化成无数掌影纷纷击向$n",
                "parry":                 -60,
                "dodge":                 -60,
                "force":                 250,
                "damage":                280,
                "post_action":               (: burn :),
                "damage_type":   "瘀伤"
        ]),
        ([      "action":               "$N左手连出虚招，接着右掌一翻使出"HIC"‘只手遮天’"NOR"，由上而下凶猛地击向$n的$l",
                "parry":                -60,
                "dodge":                -60,
                "force":                260,
                "damage":               280,
                "post_action":               (: burn :),
                "damage_type":  "瘀伤"
        ]),
        ([      "action":                "$N看准$n的破绽，一招"HIR"‘天狗食日’"NOR"左右开弓连击出两掌挟着惊天气势分取$n的要害",
                "parry":                 -60,
                "dodge":                 -60,
                "force":                 300,
                "damage":                280,
                "post_action":               (: burn :),
                "damage_type":   "瘀伤"
        ]),
        ([      "action":                "$N扑身跃向$n，双手平推，使出一招"HIB"‘暗无天日’"NOR"双掌蓦然爆发黑气遮蔽得天地黯然无光直击向$n",
                "parry":                 -60,
                "dodge":                -60,
                "force":                 350,
                "damage":                280,
                "post_action":               (: burn :),
                "damage_type":   "瘀伤"
        ]),
        });

void burn(object me, object victim, object  weapon, int damage)
{
         int burn;
         burn=victim->query_condition("burn");
message_vision("$N的真气化为一条黑龙往$n的身上缠绕,使得$n的真气慢慢的流失\n",me,victim);
         victim->apply_condition("burn",burn+1);
         victim->receive_damage("kee",30);
         victim->add("force",-40);
         COMBAT_D->report_status(victim, 1);
 }


int valid_enable(string usage) { return (usage=="unarmed" || usage=="parry"); }
mapping query_action(object me, object weapon)
{
 int i,force,kee,burn;
 object victim,*enemy;
 enemy = me->query_enemy();
 i=sizeof(enemy);
 victim = enemy[random(i)];
 burn=victim->query_condition("burn");
 force=victim->query("force",1);
 kee=220;
        if( random(100) < 10){
             message_vision(HIC"
$N大喝说：「哼！让你见识见识炎龙谷主的绝招，下地狱去吧！”


"HIB"                 灭绝一击！      "NOR"


"HIG"           ****晴天霹雳****      "NOR"
"HIR"$N口中喃喃自语，双手在胸前结成魔手印，瞬间一道真气往天空射去，忽然间
天空魔云密怖，一道黑色的闪电往$n劈去"NOR"
结果$n被雷劈中，全身麻毙，身体都不能动弹！\n",me,victim);


             victim->receive_damage("kee",(int)kee,me);
             COMBAT_D->report_status(victim);
             message_vision("


"HIG"           ****翻天覆地****    "NOR"
"HIR"$N狂笑一声，双掌合为两道真气往天空和地面指去，蓦然地面及天空产生
变化，瞬间天摇地动，混浊之气随之合为一体往$n袭去
"NOR"结果$n被混浊之气封住任督二穴，身体渐渐感到虚弱\n",me,victim);
             victim->receive_damage("kee",220,me);
             me->start_busy(1);
             COMBAT_D->report_status(victim);

                             }
return action[random(sizeof(action))];
}

