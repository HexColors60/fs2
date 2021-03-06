//金风细雨楼之黄沙万里刀法 by roger && taifar

#include <combat.h>
#include <ansi.h>
void sp_attack(object me,object victim,object weapon,int damage);
inherit SKILL;
mapping *action = ({
(["action":HIY"$N飞跃于上，刀光瞬间耀眼刺目，一式"HIW"‘日落沙丘’"HIY"急坠直下，只见一线闪光挟着剧烈风压落向$n头上"NOR,
        "damage":       400,
        "force":        400,
        "post_action":          (: sp_attack:),
        "damage_type":  "砍伤",
        "weapon"     :  "情刀",
        ]),
(["action":HIY"$N将$w"HIY"反手一握，静如豹\猎，双眼仿佛穿透了$n的心，飞闪一式"HIW"‘月冷大漠’"HIY"刀气如断月雷光直朝$n纵剖而去"NOR,
           "damage":           400,
           "force":            400,
           "post_action":          (: sp_attack:),
           "damage_type":  "割伤",
          ]),
(["action":HIY"$N振刀激尘使出一式"HIW"‘万里崩沙’"HIY"，瞬间飞沙走石，每一微小尘粒都是杀机，黄沙将$n完全封在土雾之中"NOR,
           "damage":      400,
           "force":       400,
           "post_action":          (: sp_attack:),
           "damage_type":  "砍伤",
           ]),

(["action":HIY"$N使刀若剑，"HIW"‘黄沙万里刀法’"HIY"中的一式"HIW"‘百点甘露’"HIY"在漫天尘沙之中圈出闪闪杀漪，点点错杂却尽数指向$n的眉心"NOR,
        "damage":       400,
        "force":        400,
        "post_action":          (: sp_attack:),
        "damage_type": "劈伤",
            ]),
(["action":HIY"$N忽扬一式"HIW"‘燥卷风沙’"HIY"使得突进而来的$n不得不退，并趁势追攻，只见风沙交天混杂着刀气向$n卷去"NOR,
        "damage":       400,
        "force":        400,
        "post_action":          (: sp_attack:),
        "damage_type": "劈伤",
        ]),

});

int valid_enable(string usage)
{
        return (usage=="blade")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

void sp_attack(object me,object victim, object weapon,int damage)
{
 object *enemy,target,env;
 int i,j;

 env = environment(me);
 enemy=me->query_enemy();
 i=sizeof(enemy);

 for(j=0;j < i;j++){
  target=enemy[j];
    if( env == environment(target) )
    {
     target->receive_damage("kee",150);
     COMBAT_D->report_status(target);
    }
                   }

}

