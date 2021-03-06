#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void attack(object me, object victim, object weapon, int damage);
int kar=this_player()->query("kar",1);
int cps=this_player()->query("cps",1);
int str=this_player()->query("str",1);
int cor=this_player()->query("cor",1);
int int1=this_player()->query("int",1);
int spi=this_player()->query("spi",1);
mapping *action = ({
//1
       ([    "action" :HIW
"$N凝气于掌，掌变化成爪，一招"HIR"「双龙吐珠”"HIW"，双爪有如灵龙抢珠般，飞快的\n"
"抓向$n各要害，$n眼见双爪齐攻只能闪避，但还是晚了一步，$l差点惨遭分家之痛。"NOR,
             "damage" :       150,
             "force"  :       150,
             "damage_type": "抓伤",
        ]),
//2
       ([    "action" :HIW
"$N一招"HIR"「蟠龙锁关”"HIW"单爪直下，带者猛烈的刚气，顺沿着$n的攻势，反客为主的封锁住\n"
"$n的攻势，$n顿时无以招架，被$N深深的击中胸膛，差点吐出血来。"NOR,
             "damage" :  150,
             "force"  :  150,
             "post_action":  (: attack :),
             "damage_type" :   "抓伤",
         ]),
//3
        ([   "action" :HIW
"$N暗运内息，一招"HIM"「龙凤呈祥”"HIW"，左爪右掌分别击向$n的弱点，$n顾此失彼拆卸了\n"
"$N的左爪却无从闪避，扎扎实实吃了$N一记右掌，造成气血失调。"NOR,
             "damage" :         200,
             "force"  :         200,
             "damage_type":  "掌伤",
        ]),
//4
        ([   "action" :HIW
"$N跳跃而起，身形轻盈，一招"HIM"「九天龙吟”"HIW"双掌从四面八方齐攻而下，气势有如狂风大浪般\n"
"似要把$n淹没，$n见此招运起所有功力全面抵挡，二气劲硬碰硬，差点震的$n狂吐鲜血。"NOR,
             "damage" :         200,
             "force"  :         200,
             "post_action":  (: attack :),
             "damage_type":  "掌伤",
        ]),
//5
        ([   "action" :HIW
"$N气沉丹田，侧身一翻，一招"HIG"「狂龙卷浪”"HIW"双爪凛烈，围绕着$n伺机给予重击，瞬间$N看\n"
"破$n弱点，双爪挟带凛烈的气劲，往$n身上抓去，$n急速闪避但还是被强大的气劲割伤。"NOR,
             "damage" :        250,
             "force"  :        250,
             "damage_type":  "割伤",
        ]),
//6
        ([   "action" :HIC
"$N稳固下盘，真气运走全身，一招"HIG"「虎掌生风”"HIC"双掌凝劲，$N见机行事呼哮的击出\n"
"双掌，双掌气劲狂扫而去与$n气劲相互对冲，二气劲相碰造成$n差点摔倒在地。"NOR,
             "damage" :       250,
             "force"  :       250,
             "post_action":  (: attack :),
             "damage_type":  "掌伤",
        ]),
//7
        ([   "action" :HIC
"$N吐纳内息，伺机而动，眼见$n内息不继，气喘嘘嘘，一招"HIB"「荒山虎啸”"HIC"，毫不犹豫的手肘\n"
"快顶而出，瞬时变化身形配合双拳，直向$n弱点直打而去，$n登时被打的气血贲腾，脉像杂乱。"NOR,
             "damage" :         250,
             "force"  :         250,
             "post_action":  (: attack :),
             "damage_type":  "瘀伤",
        ]),
//8

        ([      "action":HIC
"$N急吐内劲，运转周天，一招"HIB"「卧龙在野”"HIC"，$n看其气劲似柔似软，运起气劲，硬是要把其\n"
"劲挡下，其内劲看似平常无力却蕴涵无穷的内劲，等$n发觉时，气劲早已贯穿而震伤了五脏六腑。"NOR,
                "damage": 300,
                "force":  300,
                "post_action":  (: attack :),
                "damage_type":  "震伤",
        ]),
//9
        ([      "action":HIC
"$N气转至双爪，一招"HIY"「蛟龙出水”"HIC"，双爪带钩，由下而上，由后至前，向$n猛攻而去\n"
"$n顿时，对这有如波涛汹涌的巨浪气劲手足无措，登时被巨浪气劲吞嗜，造成严重出血。"NOR,
                "damage":       300,
                "force":        300,
                "post_action":  (: attack :),
                "damage_type":  "内伤",
        ]),
//10
       ([      "action" :HIC
"$N运起全身功力，气劲游走全身，不吐不快，一招"HIY"「金龙攫珠”"HIC"，挟带强大力劲往$n身上击出\n"
"数十招，招招皆击向$n身上各大穴，$n运起全身功力全力抵挡，却无法卸其锋，惨遭内劲拼击。"NOR,
               "damage":        300,
               "force":         300,
               "post_action":  (: attack :),
               "damage_type":   "经脉尽断",
        ]),

});
mapping query_action(object me, object victim, object weapon)
{
int skill, limit;
skill=(int)(me->query_skill("dragon-claw", 1));
limit=(int)(skill/10);
if(random(100) < 60)
{
if(!me->query_temp("goldheal")&&random(100)<50)
{
message_vision(sprintf(HIY"\n$N大喝一声使出少林绝学‘金钟罩’，顿时金光闪闪一道金墙陇罩在$N身旁。\n"NOR),me);
me->set_temp("goldheal",1);
} else if(!me->query_temp("unsuck")) {
message_vision(sprintf(HIY"\n$N鼓运全身内劲使出十成‘金钟罩’，试图要把敌人攻击反震回去。\n"NOR),me);
me->set_temp("unsuck",1);
}
}
if(limit<3)
{
return action[random(2)];
}
if(limit<5)
{
return action[random(4)];
}
if(limit<7)
{
return action[random(6)];
}
if(limit<9)
{
return action[random(8)];
}
else
{
return action[random(10)];
}
}

int valid_learn(object me)
{
        object ob;
        if((int)me->query("max_force",1)<3000)
        return notify_fail("你的内力不够，不能练龙爪手。\n");
        if((string)me->query_skill_mapped("force")!= "dragonforce")
        return notify_fail("燃木刀法必需配合擒龙功才能用。\n");
        if(ob=me->query_temp("weapon"))
        return notify_fail("你必须放下武器才能练龙爪手。\n");
        return 1;
}
int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry";
}
string perform_action_file(string action)
{
        return CLASS_D("bonze") + "/dragon-claw/" + action;
}

void attack(object me, object victim, object weapon, int damage)
{
switch(random(6))
{
          case 0:
                    damage = (str+cor+cps+kar+spi+int1)+120;
message_vision(sprintf(HIR"\n$N的龙爪手确确实实命中$n，$n顿时血流满地，行动变缓。\n"NOR),me,victim);
                    victim->receive_damage("kee",damage);
                    victim->start_busy(1);
                    victim->apply_condition("bleeding",10);
                    COMBAT_D->report_status(victim);
                    break;

          case 1:
message_vision("$N暗运丹田急欲抢攻，却被$n看破，只好弃攻为守。\n",me,victim);
                    break;

          case 2:
                    damage = (str+cor+cps+kar+spi+int1)*2+50;
message_vision(sprintf(HIR"\n$N擒龙功的内劲潜入$n体内，只见$n脸一阵青一阵白，似忽受伤严重。\n"NOR),me,victim);
                    victim->receive_damage("kee",damage);
                    victim->apply_condition("hurt",5);
                    COMBAT_D->report_status(victim);
                    break;

          case 3:
message_vision("$N见$n气息错乱，见机抢攻，却被$n看破，无攻而反。\n",me,victim);
                    break;

          case 4:
                   damage=(cps+int1+str+cor+kar+spi)*2+50;
message_vision(HIW"\n$N的擒龙劲与龙爪劲相互辉映，二股内劲重创$n，使$n鲜血狂吐，无法聚气。\n"NOR,me,victim);
if(victim->query("force",1)>0) victim->add("force",-(damage*5));
                   victim->receive_damage("gin",damage);
                   victim->receive_damage("kee",damage);
                   victim->receive_damage("sen",damage);
                   COMBAT_D->report_status(victim);
                   break;

          case 5:
message_vision("$N运转气劲，却无法即时吐呐，不得不暂缓攻势。\n",me,victim);
                    break;

       }
}
