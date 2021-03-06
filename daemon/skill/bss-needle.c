// yu-needle
// 七奇针诀--- 手鍼(unarmed), 针鍼(stabber)
// by adam..

#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void bleed(object me, object victim, object weapon, int damage);
void kforce(object me, object victim, object weapon, int damage);
void busyk(object me, object victim, object weapon, int damage);
void sp1(object me,object victim, object weapon, int damage);
void sp2(object me,object victim, object weapon, int damage);
void sp3(object me);
string *parry_msg=
    ({
   "$n身躯一引，指间长针平平搭在$N的武器上，一招‘"HIM" 拦雀尾"NOR" ’将$N的武器曳了开去。\n",
   "$n将身体靠向$N，一招‘"HIC" 沾衣十八跌 "NOR"’，将$N黏在原地，使不开招式!\n",
   "$n手中长针上下舞动，一招‘"HIW" 飞瀑长虹"NOR" ’, 逼得$N不得不守住自身!\n",
   "$n把手中的长针舞成圆环一招‘"HIB" 云回圆月 "NOR" ’，将$N的攻势尽数挡了下来。\n",
   "$n以静制动，手中长针平举胸前，一招‘"CYN" 如封似闭"NOR" ’，化解了$N的攻势!\n",
});

//unarmed, stabber_action

mapping *action = ({
([ "action":"$N一招‘"HIW" 白蛇吐信"NOR" ’，下身稍曲，步履前跨，双掌微分，手指尖往$n的胸前‘"HIC" 鸠尾穴"NOR" ’用力戳了去!",
        "dodge": -20,
        "parry": -20,
        "damage": 30,
        "force":  50,
        "damage_type":  "刺伤",
]),

([ "action":"$N手掌一张，一式‘"HIR" 恶虎扑羊"NOR" ’，纵身一跳，由上往下向$n的头顶‘"HIY" 百会穴"NOR" ’扑了去!",
        "dodge": -20,
        "parry": -20,
        "damage": 40,
        "force":  50,
        "damage_type": "刺伤",
]),

([ "action":"$N双手一拉一按一压，将$n的左手背‘"MAG" 合谷穴"NOR" ’制住，往外回转一圈，用力地将$n抛了开去!",
        "dodge": -20,
        "parry": -20,
        "damage": 50,
        "force":  60,
        "damage_type": "摔伤",
]),
([ "action" : "$N拗膝微蹲，倏地身躯一转，绕到了$n的背后，中指向$n背后‘"HIW" 命门穴"NOR"’戳了去!",
        "dodge": -20,
        "parry": -20,
        "damage": 60,
        "force":  70,
        "damage_type": "刺伤",
]),
([ "action" : "$N身行突然地往后退了数步，$n跟进，忽然$N身行立停，手肘一曲，转退为进，肘尖往$n腹部‘"HIR" 气血穴"NOR" ’急顶而去!",
        "dodge": -30,
        "parry": -30,
        "damage": 70,
        "force":  80,
        "damage_type": "刺伤",
]),
([ "action":"$N呼啸一声，身法轻灵地往$n背后纵了去，双手一打一戳，向$n的左边‘"HIY" 太阳穴"NOR" ’，后脑‘"HIG" 风府穴"NOR" ’攻击!",
        "dodge": -30,
        "parry": -30,
        "damage": 80,
        "force":  90,
        "damage_type": "刺伤",
]),
(["action":"$N一招‘"HIM" 转身六合"NOR" ’，身形轻轻左右摇摆\，双手上下翻动，急速地向着$n拍打，或擒拿，往$n的全身各大要穴招呼!",
        "dodge": -30,
        "parry": -30,
        "damage": 90,
        "force":  90,
        "damage_type": "刺伤",
]),

//weapon_action

([ "action":"$N左手一挥，右手一勾，一招‘"HIG" 飞花落叶"NOR"  ’，把手中$w舞向$n的双臂‘"HIG" 尺泽穴"NOR" ’!",
        "dodge": -35,
        "parry": -35,
        "damage": 90,
        "force":  90,
        "damage_type":  "刺伤",
]),

([ "action":"$N运使$w, 左右开弓, 绵绵不尽, 戳向$n的胸前‘"HIM" 膻中穴"NOR" ’, 背后‘"HIR" 肾内穴"NOR" ’",
        "dodge": -40,
        "parry": -40,
        "damage": 90,
        "force":  90,
        "damage_type": "刺伤",
        "post_action": (: busyk :),
]),

([ "action":"$N身躯一蹲，双手掐$w，平平往前直刺，一招‘"HIC" 海底翻花"NOR" ’蓄势待发，迎向$n的脚底‘"HIC" 涌泉穴 "NOR"’",
        "dodge": -45,
        "parry": -45,
        "damage": 100,
        "force":  100,
        "damage_type": "刺伤",
        "post_action": (: busyk :),
]),
([ "action":"$N身法轻灵，一招‘"HIY" 飞步拗鸾"NOR" ’，轻身一跃，$w刺向$n肩胛‘"HIW" 云门穴"NOR"’，肩顶‘"WHT" 肩胶穴"NOR" ’",
        "dodge": -45,
        "parry": -45,
        "damage": 110,
        "force":  100,
        "damage_type": "刺伤",
        "post_action": (: busyk :),]),
([ "action":"$N双臂向外一张，一式‘"HIC" 大鹏展翅"NOR" ’，紧跟一招‘"HIM" 平沙落雁"NOR" ’，手中$w疾向$n的咽喉‘"HIB" 天突穴"NOR" ’刺去!\n",
        "dodge": -45,
        "parry": -45,
        "damage": 110,
        "force":  100,
        "damage_type": "刺伤",
      "post_action": (: kforce :),
]),
([ "action":"$N身形一转，一式‘"HIM" 转身六合"NOR" ’，将手中$w舞成一股气流，回旋在$n四周，倏地一招‘"HIY" 回望春月"NOR" ’，将$w刺向$n脑门‘"WHT" 天柱穴"NOR" ’，‘"HIC" 哑门穴"NOR" ’",
        "dodge": -50,
        "parry": -50,
        "damage": 110,
        "force":  100,
        "damage_type": "刺伤",
        "post_action": (: kforce :),
]),
([ "action":"$N大喝一声‘ 绝命七针 ’，鼓动全身内劲，手中$w舞成七点光点，分别
向$n的‘"HIR" 百会穴"NOR" ’，‘"WHT" 印堂穴"NOR" ’，‘"HIC" 天突穴"NOR" ’，‘"HIM" 膻中穴"NOR" ’，‘"HIY" 中脘穴"NOR" ’，‘"MAG" 鸠尾穴"NOR" ’，‘"HIR" 气海穴"NOR" ’，急急突刺!",
        "dodge": -50,
        "parry": -50,
        "damage": 110,
        "force":  120,
        "damage_type":"刺伤",
        "post_action": (: bleed :),
]),
//后三第一式
([ "action":
HIC"        $N忽的狂舞手中的针，使出一式"HIW"ζ"HIY"七奇"HIR"秘针˙"HBBLU+HIC"月映寒道玄冰灭"NOR+HIW"ζ！！\n\n\n"NOR+
HIC"                  $N聚气针尖，使其散发出幽蓝色的光芒，旋即身影一闪，\n
          形移到敌的面前三步处，随又分身影化三，忽现一道寒芒向敌扑去，光芒过穿体\n
而过，使得敌身上"NOR"‘"HIW"手太阴肺经"NOR"’，‘"HIG"足太阴脾经"NOR"’，‘"HIC"手少阴心经"NOR"’，‘"HIR"足少阴肾经"NOR"’，‘"HIB"手厥阴心\n
          包经"NOR"’，‘"HIM"足厥阴肝经’"HIC"，六大阴经之个要穴血花斑斑，敌阴经脉受创，刹时感\n
                    到一股寒意引出，迅速遍布全身由如置身极圈中的寒灭！\n
\n"NOR,
        "dodge": -50,
        "parry": -50,
        "damage": 110,
        "force":  120,
        "damage_type":"刺伤",
        "post_action": (: sp2 :),
]),
//后三第二式，恐怖连击
([ "action":
"$N爆吼一声，对$n连绵使出不绝之势"HIW"ζ"HIY"七奇"HIR"秘针˙"HBRED+HIY"日照神州赤炎毁"NOR+HIW"ζ的极致连击！！\n"NOR,
        "dodge": -50,
        "parry": -50,
        "damage": 110,
        "force":  120,
        "damage_type":"刺伤",
        "post_action": (: sp1 :),
]),
});

//超强攻击

void bleed(object me, object victim, object weapon, int damage)
{
    int j=0;
    if (random(me->query_skill("stabber")) > 80 && me->query_temp("bleed")!=1 && me->query("class")=="doctor")
{
        me->set_temp("bleed",1);
        for(j = 0;j < 7; j++)
{
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
        COMBAT_D->report_status(victim);
}
        me->delete_temp("bleed");
    if (random(100) > 65 && !me->is_busy())
{
        me->start_busy(1);
        message_vision(HIR"$N使劲过度无法继续发动攻击!!\n"NOR,me);
    }
  }
}

void kforce(object me, object victim, object weapon, int damage)
{
if (random(me->query("functions/break-kee/level")+100) > 70 && victim->query("force_factor") > 1
    && me->query("functions/break-kee/level") > 50 && me->query("force") > 50 && me->query("class")=="doctor")
{
message_vision(HIY"$N运起破穴指顶级技巧打散$n体内的内劲!!\n"NOR,me,victim);
if (victim->query("force_factor")>1) victim->add("force_factor",-1);
if (victim->query("force") > 400) victim->add("force",-300);
me->add("force",-50);
}}
void busyk(object me, object victim, object weapon, int damage)
{
if (random(me->query("functions/gold-needle/level")+100) > 75 && me->query_temp("bleed")!=1
    && me->query("functions/gold-needle/level") > 50 && me->query("force") > 50 && me->query("class")=="doctor")
{
message_vision(HIC"$N运起金针封穴顶级技巧封阻$n的行动!!\n"NOR,me,victim);
victim->start_busy(1);
me->add("force",-50);
  }
}
void sp1(object me,object victim, object weapon, int damage)
{
        int sklv,str,i,flag;

        sklv=me->query_skill("yu-needle",1);
        str=victim->query("str");

        if(sklv >100) sklv = 100;
        sklv*=(5+random(3));//最少500,最多700
        str*=(6+random(5));//最多350(除非刚刚加完str的话就370)

        if(!damage && 500 < random(1500)) return ;//被躲掉了，不一定要这样写
        if(me->query("force") < 600) return ;//内力不够，以后可以加叙述
        if(me->query("kee") < 200) return;//kee不够也不能发
        if(me->query_temp("bleed"))//不可以又被包含在连击里面
          return ;
        if(60 < random(100) && !me->query_temp("crazy_hit")) return;
        if(me->query("family/family_name")!="银针门") return ;
        if(userp(me) && !me->query("env/六绝针")) return ;

        if(me->query_temp("crazy_hit")){
          me->delete_temp("crazy_hit");
          sklv*=2;
        }

        flag=0;
        for(i=1;i<=6;i++){
          switch(i){
            case 1:
        message_vision("
                  $N使出 --- "HBRED+HIW"◎ "HIY"赤 炎 六 绝 针 "HIW"◎"NOR" ---「"HIR"怒火燎原"NOR"”
$N"HIR"漫步提腰，双脚一横，手中的针斜斜里从而刺出，突化做一股热浪直戳向$n的"HIG"‘劳宫穴’"HIR"！\n"NOR,me,victim);
            break;
            case 2:
        message_vision("
                  $N使出 --- "HBRED+HIW"◎ "HIY"赤 炎 六 绝 针 "HIW"◎"NOR" ---「"HIR"狂绝霸炎"NOR"”
$N"HIR"双手交叉，大喝一声，右手挺针当头直刺，针忽脱手幻为一道火藤猛卷向$n的"HIC"‘膻中穴’"HIR"！\n"NOR,me,victim);
            break;
            case 3:
        message_vision("
                  $N使出 --- "HBRED+HIW"◎ "HIY"赤 炎 六 绝 针 "HIW"◎"NOR" ---「"HIR"狂心炙焰"NOR"”
$N"HIR"身随意转，手随心动，左手突发托住对方手腕，只见一阵针芒万丈猛刺向$n的"HIW"‘曲池穴’"HIR"！\n"NOR,me,victim);
            break;
            case 4:
        message_vision("
                  $N使出 --- "HBRED+HIW"◎ "HIY"赤 炎 六 绝 针 "HIW"◎"NOR" ---「"HIR"炽烈雄火"NOR"”
$N"HIR"侧身而上，两脚移步，将丹田之火贯于针尖，猛然向前直戳，针影直逼向$n的"HIM"‘紫宫穴’"HIR"！\n"NOR,me,victim);
            break;
            case 5:
        message_vision("
                  $N使出 --- "HBRED+HIW"◎ "HIY"赤 炎 六 绝 针 "HIW"◎"NOR" ---「"HIR"赤血红轮"NOR"”
$N"HIR"步走轻灵，身形向后，手捏针诀乱旋，突而针舞成轮，突现火红针网罩向$n的"HIY"‘至阳穴’"HIR"！\n"NOR,me,victim);
            break;
            case 6:
        message_vision("
                  $N使出 --- "HBRED+HIW"◎ "HIY"赤 炎 六 绝 针 "HIW"◎"NOR" ---「"HIR"玄炙火凤"NOR"”
$N"HIR"轻灵飘忽，双手后撤，手中之针突幻化为火凤翔空，口吐火浪，滚滚扑向$n的"HIB"‘百会穴’"HIR"！\n\n"NOR,me,victim);
            break;
          }
          if(50 > random(100)){
            message_vision(HIY"$N"HIY"不幸中招，伤处开始流血!!!\n"NOR,victim);
            victim->receive_damage("kee", sklv-str);
            COMBAT_D->report_status(victim);
            flag=1;
          }
          else{
            message_vision(HIG"$N"HIG"一个闪身，躲掉了致命的一针!!!\n"NOR,victim);
          }
        }
        if(flag){
          victim->apply_condition("burn", random(6)+3);
          victim->apply_condition("star-stial", random(6)+1);
          COMBAT_D->report_status(victim);
        }
        me->add("force",-600);
        message_vision("$N"HIB"因为使出了连击技，几乎耗尽了体内的真气，赶紧立定调息！！\n"NOR,me);
        me->start_busy(1);
        COMBAT_D->report_status(me);
}
void sp2(object me,object victim, object weapon, int damage)
{
        int mforce,mkee;

        if(!damage) return ;
        if(me->query("force") <100)
          return notify_fail(HIR"你使出了七奇秘针之第二式之后，由于竭尽内力，竟无力再使！\n"NOR);
        mforce = (int)me->query("max_force");
        mkee = (int)me->query("max_kee");
        victim->start_busy(random(2)+1);//这样子至少busy 1,所以me也要busy 1
        victim->apply_condition("cold", random(5)+3);
        victim->apply_condition("star-stial", random(6)+1);
        victim->receive_damage("kee",400,me);
        COMBAT_D->report_status(victim);
        me->add("force",-100);
        message_vision("$N"HIB"狂猛的使出七奇秘针之第二式之后，脑中一时血气倒转，几欲晕厥！\n"NOR,me);
        me->start_busy(random(2));
}
//后三第三式，补血式
void sp3(object me)
{
        int force;
        string out;
out=
HIW"$N运起"HIW"ζ"HIY"七奇"HIR"秘针˙"HBCYN+HIW"星炽云空极引破"NOR+HIW"ζ！！\n"NOR+
HIW"$N抓准时机，聚全身力于针锋，向着自身运功行气之"HIM"奇经八脉"HIW"刺去～～～\n
                     "HIG"【～任  脉～】"HIR"            【～督  脉～】\n
                           "HIY"【～阳  蹻～】"HIC"【～阴  蹻～】\n
                     "HIW"【～阳  维～】"NOR+RED"            【～阴  维～】\n
               "HIB"【～冲  脉～】"HIM"                        【～带  脉～】"NOR"\n
$N"HIR"一时感到体力回复了不少，又开始生龙活虎了起来！！！"NOR"\n"NOR;

        message_vision(out,me);

        force = (int)me->query_skill("force",1);
        force = force*(random(4)+2);
        me->receive_curing("gin",force);
        me->receive_curing("kee",force);
        me->receive_curing("sen",force);
        me->receive_heal("gin",force);
        me->receive_heal("kee",force);
        me->receive_heal("sen",force);
        COMBAT_D->report_status(me);
}

mapping query_action(object me, object weapon)
{
    int i, damage, sklv, limit;
    object *enemy, target;
    enemy = me->query_enemy();
    i = sizeof(enemy);
    target = offensive_target(me);
    sklv = (int)me->query_skill("yu-needle",1);
    damage = sklv+random(sklv);
    
    if(target)
{
    if(me->query("family/family_name") == "银针门" && weapon->query("id")=="pnx_needle")
    {
    if(me->query("doctor/killpnx") == 1 && sklv >= 120)
        {
        message_vision("忽然从$N手中的ζ赤焰ζ凤羽针中涌出一道炙热的暖流注入$N的四经八脉
.....\n"NOR,me,target);
        message_vision("\t$N似乎有所顿悟，意随身转使出奥义秘式－《火凤翔空》\n"NOR,me,target);
message_vision(HIR+@LONG
                                          .
                                        .::.
                                      .:::..
                                    .:::::..
                                  .:::::::..
                               .:::::::::::
                             .:::::::::::.
                          .::::::::::::::
                       .::::::::::::::::
                      ::::::::::::::::'
                      :::::::::::::::'
                       ::::::::::::::
                    .  :::::::::::.::                      '::::::'
                   .  . :::::::::::::                .:
                 .  .   ::::::::::::'            .::::::.    ':::::'   ::::'
                . .    .:::::::::::'                      ':::::::::::'
               . .   .::::::::::::'        .:::::::.
             .::.. .:::::::::::::.......:::::::.    ':::::::::.               '
          .:::: * ::::::::::::::::::::::      '::::::.        ':::::.  :::::'
       ..:::::::::::::::::::::::''''''':::::::'     '::::::.                   '
                  ':::::::::::::.            ':::::::'          :::::.     '
                    '::::::::::::.                     ':::::'      :::::
                     '::::::::::::.                           :::::'
                     .::::::::::::::
                     .::::::::::::::
                    .:::::::::::::::
                    ::::::::::::::::
                      ':::::::::::::.
                        '::::::::::::.
                          ':::::::::::.
                            '::::::::::
                              ':::::::''
                                ':::::''
                                  ':::''
                                    '::'
                                      '
LONG+NOR,me,target);
        message_vision(HIR"火凤放出道道赤炼之火，将$n包围在火光之中，$N似乎受伤不轻
...\n"NOR,me,target);
        target->apply_condition("bleeding",random(20)+5);
        target->receive_damage("kee",-sklv);
        COMBAT_D->report_status(target);
        me->add("force",-300);
        me->start_busy(1);
        }
    }
}

    limit=me->query_skill("yu-needle",1)/10;

    if(30 > random(100) && !me->query_temp("bleed") &&
       me->query("doctor/sosman") && limit >8)
       sp3(me);

    if (limit < 2 )
      return action[random(2)+2];
    if (limit == 2 )
      return action[random(3)+3];
    if (limit == 3 )
      return action[random(3)+4];
    if (limit == 4 )
      return action[random(3)+5];
    if (limit == 5 )
      return action[random(3)+6];
    if (limit == 6 )
      return action[random(3)+7];
    if (limit == 7 )
      return action[random(4)+7];
    if (limit == 8 ){
      return action[random(5)+7];
    }
    if (limit == 9 ){
      if(me->query("doctor/sosman"))
        return action[random(7)+8];
      else
        return action[random(6)+7];
    }
    if(limit>=10){
      if(me->query("doctor/sosman"))
        return action[random(7)+9];
      else
        return action[random(6)+8];
    }
}

int valid_enable(string usage)
{
    return (usage=="stabber") || (usage=="parry");
}

int practice_skill(object me)
{
        if(!me->query_temp("weapon") || !me->query_temp("secondary_weapon") )
          return notify_fail("练七奇针诀还是要拿根针吧!....\n");
        if( (int)me->query("gin") < 5 )
          return notify_fail("你的精不够，无法练习。\n");
        if( (int)me->query("kee") < 30 )
          return notify_fail("体力不够啰! 休息一下再继续练吧.\n");
        if( (int)me->query("force") < 1 )
          return notify_fail("目前内力不足,休息一会儿再练吧.\n");
        me->receive_damage("gin", 5);
        me->receive_damage("kee", 30);
        me->add("force", -1);
        return 1;
}
string query_parry_msg(string limb)
{
   return parry_msg[random(sizeof(parry_msg))];
}
string perform_action_file(string action)
{
        return CLASS_D("doctor")+"/yu-needle/"+action;
}


