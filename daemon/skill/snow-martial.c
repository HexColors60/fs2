// 对其修正 snow 加强威力 by swy
// 全新更正修改 by swy 2001/7/22
#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void diy(object me, object victim, object weapon, int damage);
void ice(object me, object victim, object weapon, int damage);
mapping *action = ({
//1
 (["action":"$N使出雪苍武学中的"HIG"‘荡风势’"NOR"，双掌一推，势如疾风暴雨般的一股狂风袭向$n的胸前",

                "dodge":                -30,
                "parry":                -20,
                "force":                 500,
                "damage":                500,
                "damage_type": "瘀伤",

       ]),
//2
(["action":"$N气运丹田，一招"HIM"‘唤雨势’"NOR"展出无数幽灵掌影往$n各处拍去",

                  "dodge":     -20,
                  "parry":     -30,
                  "force":      500,
                  "damage":     500,
                  "damage_type":     "瘀伤",

                 ]),
//3
(["action":"$N掌势惊天破云,使出雪苍武学之‘"HIW"排云掌"NOR"’，瞬时将$n的攻势如流云般泄去，并在$n的胸前烙下沈重一掌",
                  "dodge":     -20,
                  "parry":     -10,
                  "force":      500,
                  "damage":     500,
                  "damage_type":     "瘀伤",
                  "post_action":               (: diy:),

                 ]),
//4
(["action":"身形一低，一招‘"HIW"破水势"NOR"’双拳宛如蛟龙破水而出，蕴含着内劲由下而上往$n头部暴射而去",
                  "dodge":     -20,
                  "parry":     -30,
                  "force":      500,
                  "damage":     500,
                  "damage_type":     "瘀伤",
                 ]),
//5
(["action":"$N狂喝一声,一招雪苍武学之"HIW"‘扫雪式’"NOR"势如鹰扑卷起万丈暴雪般击向$n",
                  "dodge":     -30,
                  "parry":     -30,
                  "force":      500,
                  "damage":     500,
                  "damage_type":     "内伤",

                 ]),

//6
 (["action":"$N施展狂风无影身法转到$n的身后，反手抓住$n使出雪苍武学中的"HIC"‘冰龙坠’"NOR"，将$n重重的摔向地上",
                  "dodge":     -30,
                  "parry":     -45,
                  "force":     500,
                  "damage":    500,
                  "damage_type":     "摔伤",
                  "post_action":               (: diy:),

                 ]),
//7
(["action":"$N掌劲一回，使出一招"HIC"‘重云深锁’"NOR"，瞬时将$n的招式紧紧扣住，并以雪苍内劲硬震$n的内力",
                  "dodge":     -40,
                  "parry":     -70,
                  "force":      500,
                  "damage":     500,
                  "damage_type":    "内伤",

            ]),
//8
 (["action":"$N配合着无影身法，使出"HIW"‘云路魅影’"NOR"，身影令$n捉摸不定，忽然身形一滞，聚力万钧的一掌伺机往$n的$l拍去",

                  "dodge":     -70,
                  "parry":     -40,
                  "force":     500,
                  "damage":    500,
                  "damage_type":     "瘀伤",

                 ]),
//9
(["action":"$N两掌平推而去，使出雪苍武学的精华‘"HIB"崩云落"NOR"’，掌劲所至石屑纷飞，只见$n被强大的内劲压的喘不过气",

                  "dodge":     -50,
                  "parry":     -40,
                  "force":     500,
                  "damage":    500,
                  "damage_type":     "内伤",
                  "post_action":               (: diy:),

                 ]),
//10
 (["action":"$N使出雪苍派的鬼影脚，一招"HIM"‘阴府求魂’"NOR"往$n身上连踢数脚，$n顿时筋折骨裂，鲜血狂喷",

                "dodge":                -65,
                "parry":                -50,
                "force":                500,
                "damage":               500,
                "damage_type":  "瘀伤",
                 ]),
//11
 (["action":"$N使出鬼影脚中的精髓"HIR"‘风卷残云’"NOR"身形急旋下右脚如利剑般往$n的$l踢去",
                     "dodge":     -65,
                     "parry":     -60,
                     "force":     500,
                     "damage":    500,
                     "damage_type":    "刺伤",

       ]),
//12
 (["action":"$N使出鬼影脚中的精髓‘"GRN"寒梅三翦"NOR"’腿势忽变，连环三腿如影随形而至$n只感到劲风扑面袭来，命悬一线",

                     "dodge":     -65,
                     "parry":     -45,
                     "force":     500,
                     "damage_type":    "瘀伤",
                     "damage":    500,
                     "post_action":               (: diy:),

       ]),
//13
 (["action":"$N腿势暴起，踢出一招‘"HIB"浪卷千里"NOR"’劲力有如巨浪噬地绵延不绝直把$n逼的连退数十步",

                     "dodge":     -75,
                     "parry":     -75,
                     "force":     500,
                     "damage_type":    "震伤",
                     "damage":    500,

       ]),
//14
 (["action":"$N揉身而起以高制低，打出雪苍武学之精华‘"HIC"落雪漫天"NOR"’霎时只见漫天强横掌影如雪花纷飞般压向$n",

                     "dodge":     -80,
                     "parry":     -75,
                     "force":     500,
                     "damage":    500,
                     "damage_type":    "冻伤",
                     "post_action":               (: ice:),

       ]),
//15
 (["action":"$N使出雪苍武学之精华‘"HIW"玄冰掌"NOR"’，刹那间$N的四周寒气袭人，手臂上浮现一层厚冰挟着骇人气势击向$n",

                     "dodge":     -60,
                     "parry":     -70,
                     "force":     500,
                     "damage":    500,
                     "damage_type":    "冻伤",
                     "post_action":               (: ice:),
       ]),

});

void diy(object me, object victim, object weapon, int damage)
{
 int bound,dam;
 bound=(int)me->query_skill("snowforce",1);
 dam=victim->query("max_kee",1)/30;
// if(bound > 250) bound=250;
      if( me->query("force_factor") >= 5 && random(100) > 50)
      {
        if (me->query("force") > bound*2) {

message_vision(HIB"～雪苍寒劲～"NOR"
"HIC"            $N的寒劲一提，使出雪苍气劲中之"NOR"
"BLINK+HIC"                －‘ 凝 霜 劲 ’－"NOR"
"HIC"        拳势将$n笼罩，周围气温瞬间下降，将$n凝结。\n"NOR,me,victim);
              victim->receive_damage("kee",(bound+50),me);
              COMBAT_D->report_status(victim);

message_vision(HIC"～雪苍冰劲～"NOR"
"HIY"           $N将内劲往掌上凝聚，使出雪苍气劲之"NOR"
"BLINK+HIG"                 －‘ 玄 冰 劲 ’－"NOR"
"HIY"        掌上劲力瞬时提升数倍，澎湃的掌劲向$n袭卷而去。\n"NOR,me,victim);
              victim->receive_wound("kee",(bound+50),me);
              COMBAT_D->report_status(victim);
              me->add("force",-bound*2);

         }
       }
}

void ice(object me, object victim, object weapon, int damage)
{
int bound,age,me_exp;
bound=(int)me->query_skill("snowforce",1);
//if(bound > 250) bound=250;
        if( me->query("force",1) >= 500  &&
        random(100)>50)
           {
message_vision(HIW"\n$N的寒劲更使得$n的身上结成一层薄冰，造成严重冻伤，功力大减。\n\n"NOR,me,victim);
              victim->apply_condition("cold",random(15)+1);
              victim->receive_wound("kee",(bound+350),me);
              victim->add("force",-140);
              COMBAT_D->report_status(victim);
              me->add("force",-200);
           }
}


int valid_learn(object me)
{

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") ) {
               write("学雪苍武学必需空手。\n");
               return 0;
        }
        if(me->query("max_force")<50) {
                write("喂! 小子, 内力上限要 50 喔，等你长大点再来。\n");
                return 0;
        }
        if(me->query_skill("snowforce",1)<10) {
                write("你的雪苍派内功火候不够，不能练雪苍武学。\n");
                return 0;
        }
        if(me->query("family/family_name") != "雪苍派")
        {
               write("只有雪苍弟子可以学!!!!\n");
               return 0;
           }

        return 1;
}

int valid_enable(string  usage)  {

            return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
 int i,j,k,force,kee,star,skill,bound,dam;
 object victim,*enemy;
 victim = offensive_target(me);
 dam=victim->query("max_kee",1)/50;
 if(dam > 2500) dam=2500;
 skill=me->query_skill("snow-martial",1);
 bound=skill;
 k=random(100);
//武器特功的部份..by chan
weapon=me->query_temp("weapon");
// 以下是合技的使用过的计号和消除 by swy
if(random(100)>80 && me->query_temp("use-two-power")) {
me->delete_temp("use-two-power");
}
if(weapon)
{
if(me->query("family/family_name")=="雪苍派" && weapon->query("id")=="figring")
{
 if((skill>90)&&(k>80)&&me->query_skill_mapped("force")=="snowforce" && victim)
  {
message_vision(HIW"$N手上的"HIC"金钢指环"HIW"被$N的雪苍寒劲所引,$N全身发出数道光茫,变成一只凶猛的雪虎!!\n"NOR,me,victim);
message_vision(HIW+@LONG

                       _ __..-;''`--/'/ /.',-`-.
                   (`/' ` |  \ \ \\ / / / / .-'/`,_
                  /'`\ \   |  \ | \| // // / -.,/_,'-,
                 /<7' ;  \ \  | ; ||/ /| | \/    |`-/,/-.,_,/')
                /  _.-, `,-\,__|  _-| / \ \/|_/  |    '-/.;.\'
                `-`  f/ ;      / __/ \__ `/ |__/ |
                     `-'      |  -| =|\_  \  |-' |
                           __/   /_..-' `  ),'  //
                          ((__.-'((___..-'' \__.'

LONG+NOR,me);
message_vision(HIC"残暴的巨大雪虎,发出巨大啸声!!,对$n展开猛烈的攻击!!!\n"NOR,me,victim);
message_vision(HIW"雪虎快速的挥舞锐利的爪子,$n闪躲不及全身皮绽肉裂!!\n"NOR,me,victim);
victim->receive_damage("kee",100,me);
COMBAT_D->report_status(victim);
message_vision(HIW"一道锐利的声音破空而出,$n被雪虎的尾巴扫到,感觉全身被撕开!!\n"NOR,me,victim);
victim->receive_damage("kee",100,me);
COMBAT_D->report_status(victim);
message_vision(HIW"雪虎用锐利的牙咬住了$n的身体,强烈的寒气从雪虎身上发出让$n感觉生不如死!!\n"NOR,me,victim);
victim->apply_condition("cold",random(15)+1);
victim->receive_damage("kee",100,me);
COMBAT_D->report_status(victim);
message_vision(HIY"奇特的光茫从凶猛的雪虎身上发出,强光过后$N变成了人形了!!\n"NOR,me);
me->add("force",-250);
}
}
}
if(me->query("force_factor")<80) {
if((me->query("quests/read_snow")==1) && skill >= 70 &&
me->query("family/family_name")=="雪苍派"&&me->query("force",1) > 500){
if(random(100) > 80 && victim) {
   bound=bound+100;
   message_vision(HIM"\n\n$N对$n使出了雪苍武学之绝招 ---‘ 夺 命 三 掌 ’!!\n"NOR,me,victim);
   victim->apply_condition("cold",random(15)+1);
message_vision(HIC"\n\n$N使出"HIW"夺命三掌第一招"HIG"‘疾风狂袭’"HIC"，双掌一推，势如疾风暴雨般的一股狂风袭向$n的胸前\n"NOR,me,victim);
         victim->receive_damage("kee",bound,me);
         COMBAT_D->report_status(victim);
      bound=bound+100;
message_vision(HIC"\n\n$N气运丹田，使出"HIW"夺命三掌第二招"HIM"‘迷踪乱雪’"HIC"展出无数幽灵掌影往$n各处拍去\n"NOR,me,victim);
         victim->receive_wound("kee",bound,me);
         COMBAT_D->report_status(victim);
      bound=bound+100;
message_vision(HIC"\n\n$N掌势惊天排云，使出雪苍"HIW"夺命三掌最后一招‘"HIC"夺"HIW"命"HIC"掌"NOR"’"HIC"，瞬时将$n的攻势如云般泄去，并在$n的胸前烙下沈重一掌\n"NOR,me,victim);
   victim->receive_wound("kee",dam,me);
         me->add("force",-240);
         COMBAT_D->report_status(victim);
  }
 }

if((me->query("quests/read_snow")==2) && skill >= 70 &&
me->query("family/family_name")=="雪苍派"&&me->query("force",1) > 500){
  if(random(100) > 80 && victim) {
 message_vision(HIG"\n\n$N对$n使出了雪苍武学之绝招 ---‘ 狂 风 无 影 脚 ’!!\n"NOR,me,victim);
 victim->apply_condition("cold",random(15)+1);
   for(j=1;j<=9;j++)
   {
  switch(1+random(4))
   {
case 1:
message_vision(HIR"                 －－狂风鬼影脚－－"NOR"
"HIW"    $N将气劲一转，气劲源源不断的向脚上凝聚，使出雪苍气劲之"NOR"
"BLINK+HIR"                     ～‘ 狂 风 劲 ’～"NOR"
"HIW"             $N的脚风如狂风般的脚势向$n狂袭而去。\n"NOR,me,victim);
               victim->receive_damage("kee",bound,me);
         me->add("force",-30);
         COMBAT_D->report_status(victim);
break;
case 2:
message_vision(GRN"                 －－烈风乱影脚－－"NOR"
"HIC"    $N将内力一放，气劲源源不断的向脚上凝聚，使出雪苍气劲之"NOR"
"BLINK+GRN"                    ～‘ 烈 风 劲 ’～"NOR"
"HIC"             $N的脚如闪电般的脚势向$n残踢而去。\n"NOR,me,victim);
         victim->receive_damage("kee",bound,me);
         me->add("force",-30);
         COMBAT_D->report_status(victim);
break;
case 3:
message_vision(HIB"                 －－旋风幻影脚－－"NOR"
"HIC"    $N将内力一收，气劲源源不断的向脚上凝聚，使出雪苍气劲之"NOR"
"BLINK+HIB"                    ～‘ 旋 风 劲 ’～"NOR"
"HIC"             $N的腿顺势一转由上至下向$n劈踢而去。\n"NOR,me,victim);
         victim->receive_wound("kee",bound,me);
         me->add("force",-30);
         COMBAT_D->report_status(victim);
break;
case 4:
message_vision(HIY"                 －－暴风灭影脚－－"NOR"
"HIC"    $N将内劲暴射，气劲源源不断的向脚上凝聚，使出雪苍气劲之"NOR"
"BLINK+HIY"                    ～‘ 暴 风 劲 ’～"NOR"
"HIC"             $N强横的内力挟带着破风之声向$n猛踢而去。\n"NOR,me,victim);
           victim->receive_wound("kee",dam,me);
         me->add("force",-30);
         COMBAT_D->report_status(victim);
break;
}
   }
                       }
                       }
if((me->query("quests/read_snow")==3) && skill >= 70 &&
(me->query("family/family_name")=="雪苍派") && (me->query("force",1) > 500)){
     if(random(100) > 80 && victim){
message_vision(HIW"\n\n$N对$n使出了雪苍武学之绝招 ---‘ "HIY"枯"HIB" 叶"HIM"残"HIG" 星"HIW" 掌 ’"NOR"!!

            "HIC"$N体内的寒气蓦然爆发，忽然间一团星状之真气快速飞向$n
            刹那间$n的胸前立刻出现了一个紫黑色的伤痕，全身打颤不已!
\n\n"NOR,me,victim);
     victim->receive_wound("kee",(100+bound*7),me);
     victim->apply_condition("star-stial",random(15)+1);
     me->add("force",-200);
     COMBAT_D->report_status(victim);
                         }
                         }
} else {
if(me->query("family/family_name")=="雪苍派"&&skill==100&&me->query("force")>1000) {
if(random(100)>85&&victim) {
message_vision(HIW"\n$N对$n使出了雪苍武学之奥义 ---‘ 绝 学 三 连 击 ’---\n\n"NOR,me,victim);
for(i=1;i<=8;i++) {
switch(i) {
case 1:
message_vision(HIY"            ---‘疾风狂袭’---"NOR"
"HIC"    $N双掌一推，势如疾风暴雨般的一股狂风袭向$n的胸前。\n"NOR,me,victim);
               victim->receive_damage("kee",180,me);
               me->add("force",-100);
               COMBAT_D->report_status(victim);
break;
case 2:
message_vision(HIM"            ---‘迷踪乱雪’---"NOR"
"HIC"    $N展出无数幽灵掌影往$n各处拍去。\n"NOR,me,victim);
               victim->receive_wound("kee",240,me);
               me->add("force",-100);
               COMBAT_D->report_status(victim);
break;
case 3:
message_vision(HIW"            ---‘"HIC"夺"HIW"命"HIC"掌"NOR"’---"NOR"
"HIC"    $N瞬时将$n的攻势如云般泄去，并在$n的胸前烙下沈重一掌。\n"NOR,me,victim);
               victim->receive_wound("kee",dam,me);
               me->add("force",-100);
               COMBAT_D->report_status(victim);
break;
case 4:
message_vision(HIR"            ---‘狂风鬼影脚’---"NOR"
"HIW"    $N将气劲一转，气劲源源不断的向脚上凝聚，使出雪苍气劲之"NOR"
"BLINK+HIR"                     ～‘ 狂 风 劲 ’～"NOR"
"HIW"             $N的脚风如狂风般的脚势向$n狂袭而去。\n"NOR,me,victim);
               victim->receive_damage("kee",180,me);
               me->add("force",-100);
               COMBAT_D->report_status(victim);
break;
case 5:
message_vision(GRN"            ---‘烈风乱影脚’---"NOR"
"HIC"    $N将内力一放，气劲源源不断的向脚上凝聚，使出雪苍气劲之"NOR"
"BLINK+GRN"                    ～‘ 烈 风 劲 ’～"NOR"
"HIC"             $N的脚如闪电般的脚势向$n残踢而去。\n"NOR,me,victim);
         victim->receive_wound("kee",240,me);
         me->add("force",-100);
         COMBAT_D->report_status(victim);
break;
case 6:
message_vision(HIB"            ---‘旋风幻影脚’---"NOR"
"HIC"    $N将内力一收，气劲源源不断的向脚上凝聚，使出雪苍气劲之"NOR"
"BLINK+HIB"                    ～‘ 旋 风 劲 ’～"NOR"
"HIC"             $N的腿顺势一转由上至下向$n劈踢而去。\n"NOR,me,victim);
         victim->receive_damage("kee",180,me);
         me->add("force",-100);
         COMBAT_D->report_status(victim);
break;
case 7:
message_vision(HIY"            ---‘暴风灭影脚’---"NOR"
"HIC"    $N将内劲暴射，气劲源源不断的向脚上凝聚，使出雪苍气劲之"NOR"
"BLINK+HIY"                    ～‘ 暴 风 劲 ’～"NOR"
"HIC"             $N强横的内力挟带着破风之声向$n猛踢而去。\n"NOR,me,victim);
           victim->receive_wound("kee",dam,me);
           me->add("force",-100);
           COMBAT_D->report_status(victim);
break;
case 8:
message_vision(HIW"            ---‘ "HIY"枯"HIB" 叶"HIM"残"HIG" 星"HIW" 掌 ’---"NOR"
"HIC"    $N体内的寒气蓦然爆发，忽然间一团星状之真气快速飞向$n"NOR"
"HIC"    刹那间$n的胸前立刻出现了一个紫黑色的伤痕，全身打颤不已。\n\n"NOR,me,victim);
     victim->receive_wound("kee",dam*2,me);
     victim->apply_condition("star-stial",random(20)+1);
     victim->apply_condition("cold",random(20)+1);
     me->add("force",-150);
     COMBAT_D->report_status(victim);
break;
}
}
}
}
}
   if( skill < 20)
      return action[random(3)];
   else if( skill < 40)
      return action[random(5)];
   else if( skill < 50)
      return action[random(7)];
   else if( skill < 60)
      return action[random(6)+3];
   else if( skill < 80)
      return action[random(8)+3];
  else if( skill < 90)
      return action[random(8)+5];
   else
      return action[random(8)+7];
}
int practice_skill(object me)
{

        if( (int)me->query("kee") < 30 )
                      return  notify_fail("你的气不够，无法练习雪苍武学。\n");
        if( (int)me->query("force") < 5 )
                   return  notify_fail("你的内力不够，不能练习雪苍武学。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
string perform_action_file(string action)
{
        return CLASS_D("fighter")+"/snow-martial/"+action;
}

