//星夜艳梦刀法 by roger && taifar
//金风细雨第九楼楼主李梦枕skill
#include <combat.h>
#include <ansi.h>
inherit SKILL;
void sp_attack(object me,object victim,object weapon,int damage);
void sp_attack1(object me,object victim,object weapon,int damage);
void sp_attack2(object me,object victim,object weapon,int damage);
void sp_attack3(object me,object victim,object weapon,int damage);
void sp_attack4(object me,object victim,object weapon,int damage);
void sp_attack5(object me,object victim,object weapon,int damage);
void sp_attack6(object me,object victim,object weapon,int damage);
void sp_attack7(object me,object victim,object weapon,int damage);
void sp_attack8(object me,object victim,object weapon,int damage);
void sp_attack9(object me,object victim,object weapon,int damage);
void sp_attack10(object me,object victim,object weapon,int damage);
int kar=this_player()->query("kar",1);
int cps=this_player()->query("cps",1);
int str=this_player()->query("str",1);
int cor=this_player()->query("cor",1);
int int1=this_player()->query("int",1);
int spi=this_player()->query("spi",1);
int sp_value;

mapping *action = ({
//1
(["action":HIC"$N轻舞$w使出一式"HIY"‘夜女清芬’"HIC"，刀光悠远，像丽人倩影圈撒淡淡香氲，艳烈的刀气瞬间直奔$n喉间"NOR,
        "damage":       850,
        "force":        850,
        "post_action":          (: sp_attack:),
        "post_action":          (: sp_attack1:),
        "damage_type":  "砍伤",
        "weapon"     :  "情刀",
        ]),
//2
(["action":HIC"$N刀锋侧转使出一式"HIY"‘夕若蘅芷’"HIC"，伴着红红刀光沁出郁郁香气，刃随风卷，赤虹刀气如夕霞突落在$n眼前"NOR,
        "damage":           850,
        "force":            850,
        "damage_type":  "割伤",
        "post_action":          (: sp_attack1:),
        "damage_type":  "砍伤",
           "weapon"     :  "情刀",
          ]),
//3
(["action":HIC"$N倏地回刀，一式"HIY"‘梦醉风铃’"HIC"的破风声犹如一串风过时的铃响，刀气形成美丽的弧线高掠过空直坠$n脑门"NOR,
        "damage":      850,
        "force":       850,
        "damage_type":  "砍伤",
        "post_action":          (: sp_attack:),
        "post_action":          (: sp_attack1:),
           "weapon"     :  "情刀",
           ]),

//4
(["action":HIC"$N飞身一式"HIY"‘星香蕉叶’"HIC"，刀光轮转，身影轻的就像一阵微风迫近$n，刃裂狂旋，乱扫$n的四肢"NOR,
        "damage":       850,
        "force":        850,
        "post_action":          (: sp_attack:),
        "damage_type": "劈伤",
        "weapon"     :  "情刀",
            ]),
//5
(["action":HIC"$N压身反转刀柄突刺$n的双膝使出"HIY"‘星夜醉梦刀法’"HIC"中的"HIY"‘睡露海棠’"HIC"，在眨眼间回刀上扬平扫落刃袭向$n$l"NOR,
        "damage":       850,
        "force":        850,
        "damage_type": "劈伤",
        "post_action":          (: sp_attack:),
        "weapon"     :  "情刀",
        ]),
//6
(["action":HIC"$N提足划上"HIY"‘星夜醉梦刀法’"HIC"，使出了一式‘借柳挂月’，$w在空中旋出粼粼弧光飒成银月，月凛刀气直落$n$l"NOR,
        "damage":       850,
        "force":        850,
        "post_action":          (: sp_attack:),
        "damage_type": "劈伤",
        "weapon"     :  "情刀",
        ]),
//7
(["action":HIC"$N若有似无，藉由"HIY"‘星夜醉梦刀法’"HIC"刀意，使出了一式‘如梦似醉’，$w在$N手中划出阵阵银光直落$n$l"NOR,
        "damage":       850,
        "force":        850,
        "post_action":          (:sp_attack2:),
        "damage_type": "劈伤",
        "weapon"     :  "情刀",
        ]),

//8
        ([      
                "action"     :HIC"$N运起身上"HIY"‘残阳’"HIC"气劲，以刀代剑使出仙剑禁断之"HIY"‘残阳千里’"HIC"，瞬间身化残影落步，剑尖分指$n$l"NOR,
                "dodge"      :               -500,
                "parry"      :               -500,
                "damage"     :                830,
                "force"      :                830,
                "post_action":                (: sp_attack3 :),
                "damage_type":               "刺伤"
        ]),
//9
        ([     
                "action"     :               HIC"$N步若游光以刀代剑，使出仙剑禁断之连阳七诀第四式"HIY"‘暖阳无锋’"HIC"，剑气烘燃，一流宏大的剑压曲地逼近$n"NOR,
                "dodge"      :                -500,
                "parry"      :                -500,
                "damage"     :                840,
                "force"      :                840,
                "post_action":                (: sp_attack4 :),
                "damage_type":               "刺伤"
        ]),
//10
        ([   
                "action"     :               HIC"$N飞身高跃倏然使出了仙剑禁断之连阳七诀第三式"HIY"‘艳阳无情’"HIC"，刀光如浩日辉煌，笔直落在$n眉心"NOR,
                "dodge"      :                -500,
                "parry"      :                -500,
                "damage"     :                850,
                "force"      :                850,
                "post_action":                (: sp_attack5 :),
                "damage_type":               "刺伤"
        ]),
//11
        ([  
                "action"     :               HIC"$N，心若止水刀光潋艳，瞬间使出仙剑禁断之连阳七诀"HIY"‘冬阳无意’"HIC"泛起波波杀意如刃向$n绕流而去"NOR,
                "dodge"      :                -500,
                "parry"      :                -500,
                "damage"     :                870,
                "force"      :                870,
                "post_action":                (: sp_attack6 :),
                "damage_type":               "割伤"
        ]),
//12
        ([ 
                "action"     :               HIC"$N手里的$w"HIC"配上身上无比剑气，带动一招仙剑禁断之"HIY"‘夕阳无意’"HIC"犹如霞光满天尽落$n身上"NOR,
                "dodge"      :                -500,
                "parry"      :                -500,
                "damage"     :                880,
                "force"      :                880,
                "post_action":                (: sp_attack7 :),
                "damage_type":               "割伤"
        ]),
//13
        ([
                "action"     :               HIC"$N以刀代剑峰回路转，内劲猛然上窜使出仙剑禁断"HIY"‘烈阳气杀’"HIC"，剑光如烈阳狂焰直奔$n心口"NOR,
                "dodge"      :                -500,
                "parry"      :                -500,
                "damage"     :                890,
                "force"      :                890,
                "post_action":                (: sp_attack8 :),
                "damage_type":               "刺伤"
        ]),
//14
         ([     "action"     :               HIC"$N将$w"HIC"收鞘而入，身上朝阳昊气带动无上剑气，聚精凝神使出仙剑禁断之"HIY"‘朝阳再现’"HIC"，只见剑光如晨光乍现划向$n"NOR,
                "parry"      :                -500,
                "dodge"      :                -500,
                "damage"     :                900,
                "force"      :                900,
                "post_action":                (: sp_attack9 :),
                "damage_type":                "割伤",
           ]),
//15
         ([     "action"     :               HIM"$N融合身上刀剑双绝之奥妙，配合身上修罗斗气，聚精凝神将两大绝学融为一体，使出刀剑双绝之"HIY"‘刀行剑旋’"HIM"，只见刀光剑光快如流星，划向$n"NOR,
                "parry"      :                -700,
                "dodge"      :                -700,
                "damage"     :                1000,
                "force"      :                1000,
                "post_action":                (: sp_attack10 :),
                "damage_type":                "割伤",
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
 int i;
 if(random(100) > 50 && !me->query_temp("conti")){
message_vision(HIM"\n$N随风一笑，情刀流香郁郁，星光迷离，刀光一散如细细的雨般往$n洒去，令人陶醉 \n"NOR,me,victim);
  victim->start_busy(2);
  me->set_temp("conti",1);
   for(i=0;i<5;i++)
    
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
                   
  me->delete_temp("conti");
                     }
}
void sp_attack1(object me,object victim, object weapon,int damage)
{
 int i;
 if(random(100) > 50 && !me->query_temp("conti")){
message_vision(HIM"\n$N随风一笑，情刀流香郁郁，星光迷离，刀光一散如细细的雨般往$n洒去，令人陶醉 \n"NOR,me,victim);
  me->set_temp("conti",1);
   for(i=0;i<2;i++)
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

  me->delete_temp("conti");
                     }
}
void sp_attack2(object me,object victim, object weapon,int damage)
{
 message_vision(sprintf(HIC"$N人随意转，转眼间来到$n身后，$n发觉急忙转身回挡，只见$N绕到另一侧并使出其本身真气发出流星般的一击 \n"NOR),me,victim);
 victim->start_busy(2);
 message_vision(sprintf(HIC"$n中招后愣了一下，瞬间$N浩翰真气已席卷而至 \n"NOR),me,victim);
 victim->apply_condition("tsunami",random(4)+2);
 COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
 }
void sp_attack3(object me, object victim, object  weapon, int damage)
{
  sp_value =10*(str+cor)+cps+kar+spi+int1;
message_vision(HIY"
就在$n被击中的瞬间，$N心转"HIR"‘残阳千意’"HIY"，乱步分影遮光为幻
一心千切，同一把刀，舞的却是不同的招式，招招朝着$n的要穴窜去
\n"NOR,me,victim);
    victim->receive_damage("kee",sp_value,me);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

}

void sp_attack4(object me, object victim, object  weapon, int damage)
{
  sp_value =7*(str+cor)+cps+kar+spi+int1;

    message_vision(HIW"
刀气流动，随着$N的心念越发强烈，$n无从反动，完完全全
受到刀压的控制，衍生一式"HIY"‘暖阳印境’"HIW"激出的刀芒在空中不停地聚
合盘旋，刹那间!!天地变色风起云涌，一轮暖日在空气之间现形而生
$n被此情景所震慑，一瞬间已被吞没于光芒之中
\n"NOR,me,victim);
   victim->receive_damage("kee",sp_value,me);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}

void sp_attack5(object me, object victim, object  weapon, int damage)
{
  sp_value =7*(spi+int1)+cps+kar+str+cor;

    message_vision(HIY"
就在同时，$N心扩天地，怀若宇宙，狂奔的戾气瞬间平息，$N与
天地仿佛结合为一，瑞光艳丽光彩夺目，凝止住全部的的动作 
一式"HIW"‘艳阳三刀--天罡\-地煞-人祸’"HIY"迅如雷光落向$n
\n"NOR,me,victim);

   victim->receive_damage("kee",sp_value,me);
   victim->set_temp("no_power",1);
   victim->apply_condition("no_power",2);
   COMBAT_D->report_status(victim);
}

void sp_attack6(object me, object victim, object  weapon, int damage)
{
  sp_value =7*(cps+kar)+str+cor+spi+int1;
     message_vision(HIW"
$N内劲顿转使出连阳唯一阴寒之招，瞬时间一股寒气笼罩身旁，只见
刀上薄冰渐起幻成冰柱，$N愈使愈快，宛若汹涌巨浪瞬时压力遽增
霎时四周水波云气变化万千，$n瞬间分不清刀在何方, 就在迟疑之
际，$N一式"HIC"‘冬阳天冰’"HIW"卷起狂霜乱雪直捣$n心口
\n"NOR,me,victim);

    victim->receive_damage("kee",sp_value,me);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}

void sp_attack7(object me, object victim, object  weapon, int damage)
{
    int i;
  sp_value =8*(cps+kar)+str+cor+spi+int1;
    message_vision(HIR"
$N趁势翻身飞跃，斜回刀尖，念转灵动使出"HIW"‘红染夕阳’"HIR"，霎时
杀意狂奔，欲噬血腥无法自制，刀鼓风旋，连锁成无数无形风刃，削
肉刮骨欲罢不能
"NOR,me,victim);
    victim->receive_damage("kee",sp_value,me);
    me->set_temp("conti",1);
    for(i=0; i<3 ;i++)
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    me->delete_temp("conti");
    
}

void sp_attack8(object me, object victim, object  weapon, int damage)
{
  int i;
  sp_value =8*(cps+kar)+str+cor+spi+int1;
  message_vision(HIR"
  眨眼间，剑锋泛火，火光渐如焰日逼人，$N如化祝融全身火红蓦地一声大喝
  "HIW"‘"HIR"艳阳气杀"HIW"’"HIR"，手中兵器犹似火龙摧天，刀幻千万火只在一瞬间$n已完全火龙被吞没"NOR,me,victim);
  message_vision("$N闪躲不及，身上顿时多出了一道血淋淋的剑痕。\n" , victim);
    victim->receive_damage("kee",sp_value,me);
    victim->set_temp("swordkee",1);
    victim->apply_condition("swordkee",6);
    COMBAT_D->report_status(victim);
}


void sp_attack9(object me, object victim, object  weapon, int damage)
{
int i;
sp_value =8*(str+cor+cps)+spi+int1+kar;
message_vision(HIY"
$N身上随着‘朝阳再现’这一式散发出开天潜藏的灵气，刹那间!刀泛金光
完全照亮了暗影，如千百个太阳在$N的手中，一齐射出无与伦比的金光，令
$n根本无法逼视\n"NOR,me,victim);
    victim->receive_wound("kee",sp_value+130,me);
    victim->start_busy(1);
    victim->set_temp("no_power",1);
    victim->apply_condition("no_power",2);
    COMBAT_D->report_status(victim);
}

void sp_attack10(object me, object victim, object  weapon, int damage)
{
int i;
sp_value =10*(str+cor+cps)+spi+int1+kar;
message_vision(HIM"
$N身上随着‘刀形剑旋’这一式散发出浩然正气，刹那间，$N身上窜出
一刀一剑之气芒，若隐若现令人防不胜防，$n根本无法闪躲\n"NOR,me,victim);
    victim->receive_wound("kee",sp_value+130,me);
    victim->start_busy(2);
    victim->apply_condition("swordkee",2);
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
}

