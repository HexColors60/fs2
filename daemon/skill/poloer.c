#include <combat.h>
#include <ansi.h>
inherit SKILL;
void upforce(object me, object victim, object  weapon, int damage);
void god_att(object me, object victim, object  weapon, int damage);
void shooting_att(object me,object *victim,object weapon,int damage);
int remove_upforce(object me);

mapping *arrow_action = ({
// 1
        ([      "action":
HIR" $N"NOR" 随风运转"CYN"，"NOR"初招乍现"CYN"，"NOR"霎时间"CYN"，"NOR
"$c已随"HIB"$N"NOR"$P应手架于$w之身"CYN"，"NOR"随象万变而去"CYN"，"NOR
"刹时$c已从"HIB"$N"NOR"之手飞往 "HIY"$n"NOR" 的$l"CYN"，"NOR,
                "dodge":       -10,
                "parry":       -30,
                "damage":       200,
                "force":        200,
                "damage_type": "刺伤",
              "post_action":  (:god_att :),
                ]),
// 2
        ([      "action":
HIR" $N"NOR" 使着优雅的指尖"CYN"，"NOR"从身后抽出了一支$c"CYN"，"NOR"随着"HIB"$N"
NOR"$P的手臂在空中甩出一个半圆"CYN"，"NOR"只见$c如流风般射向 "HIY"$n"CYN" ，"
NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       200,
                "force":        200,
                "damage_type": "刺伤",
                "post_action":  (:upforce:),
        ]),
// 3
        ([      "action":
HIR" $N"NOR" 高举起$w"CYN"，"NOR"锐利的$c顺着$w在半空中画下一道完美的弧线"CYN"，"
NOR"随式一招"HIC"「"HIG"阡陌人回"HIC"”"NOR"往 "HIY"$n"NOR" 的$l飞射直去"CYN
"，"NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       200,
                "force":        200,
                "damage_type": "刺伤",
        ]),
// 4
        ([      "action":
HIR" $N"NOR" 轻巧地将$c搭于$w之上"HIW"，"NOR"使出流星箭疾诀□奔式"HIC"「"HIM
" 一泄千里 "HIC"”"HIW"，"NOR"霎时箭势如奔流狂河疾去"HIW"，"NOR"遁地而行"HIW
"，"NOR"直射 "HIY"$n"NOR" 的下盘"HIW"，"NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       100,
                "force":        100,
                "damage_type": "射伤",
   "post_action":    (:shooting_att :),
        ]),
// 5
        ([        "action":
HIR" $N"NOR" 将内力运如浪波不断贯入$w上之$c"HIW"，"NOR"使出流星箭疾诀□破式"
HIC"「"HIB" 破龙惊天 "HIC"”"HIW"，"NOR"只见$c箭身旋气不羁"HIC"，"NOR
"如恶龙狂噬般地朝 "HIY"$n"NOR" 的$l狂奔击去"HIC"，"NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       150,
                "force" :       150,
                "damage_type": "射伤",
"post_action": (:god_att:),
]),
// 6
        ([      "action":
HIR" $N"NOR" 以落英之势回荡手肘"HIC"，"NOR"奔放之态取出$c搭于$w"HIC"，"NOR
"弹指之间$c已射出"HIC"，"NOR"这正是流星箭疾诀□落式"HIW"「"HIY"万昂寰宇"
HIW"”"HIC"，"NOR"箭势仓昂隽洁"HIC"，"NOR"直奔 "HIY"$n"NOR" 的$l而去"HIC"，"NOR,
                "dodge":         -10,
                "parry":         -30,
                "damage":        150,
                "force":         150,
                "damage_type": "射伤",
                "post_action": (: upforce :),
        ]),
// 7
        ([      "action":
HIR" $N"NOR" 手落万方"HIW"，"NOR"以内力辅助气息之运行"HIW"，"NOR"$c似流星狂飞向"
HIR"$n"NOR"的$l狂奔而去"HIW"，"NOR"此招正式流星箭疾诀□醉式"BLU"「"HIB
"衔觞射日"BLU"”"NOR+HIW"，"NOR"$c箭势拔挺立魄"HIW"，"NOR"雄风伟健"HIW"，"NOR
"奔向 "HIY"$n"NOR" 的$l"HIW"，"NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       170,
                "force":        170,
                "damage_type": "射伤",
                "post_action": (: shooting_att:),        
]),
// 8
        ([      "action":
HIR" $N"NOR" 聚气凝神"HIW"，"NOR"静其心志"HIW"，"NOR"手执$w直视"HIY"$n"NOR+HIW
"，"NOR"$c以万马奔腾之势飞泄而出"HIW"，"NOR"此招正是流星箭疾诀□静式"GRN
"「"HIG"望穿秋水"GRN"”"NOR+HIW"，"NOR"直冲 "HIY"$n"NOR" 的$l"HIW"，"NOR,
                "dodge":       -10,
                "parry":       -30,
                "damage":       200,
                "force":        200,
                "damage_type": "射伤",
        ]),
// 9
        ([      "action":
HIR" $N"NOR" 调停内息"HIW"，"NOR"发劲于手中的$c上"HIW"，"NOR"左手放弦任箭飞扬"HIW
"，"NOR"此招乃是流星箭疾诀□烈式"RED"「"HIR"烈日俦阳"RED"”"NOR+HIW"，"NOR
"气势滂沱"HIW"，"NOR"箭疾风嘐"HIW"，"NOR"直往 "HIY"$n"NOR" 的$l射去"HIW"，"NOR,
                "dodge":       -10,
                "parry":      -30,
                "damage":       220,
                "foece":        220,
                "damage_type": "射伤",
                "post_action": (:god_att:),        
]),
// 10
        ([      "action":
HIR" $N"NOR" 以躬代剑"HIY"，"NOR"身步轻盈迅捷猛建"HIY"，"NOR"直奔 "HIR"$n"NOR
" 眼前"HIY"，"NOR"以弓身直劈 "HIY"$n"NOR" 的$l"HIY"，"NOR
"此招乃是流星箭疾诀□无箭式"HIC"‘诛天落日’"HIY"，"NOR"力道猛击 "HIY"$n ，"
NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       250,
                "force":        250,
                "damage_type": "射伤",
        ]),
// 11
        ([      "action":
HIR" $N"NOR" 以手握$c"HIY"，"NOR"睥睨 "HIY"$n"NOR" 而威气不减"HIY"，"NOR"意入"
HIC"冰心诀"NOR"中"HIW"舞弄起清影"NOR"的境界"HIY"，"NOR"箭势虎魄龙威"HIY"，"NOR
"浩气直逼 "HIY"$n"HIY" ，"NOR"气道直冲手腕"HIY"‘奔池、落合’"NOR"二穴"HIY"，"
NOR"适时下使流星箭疾诀□疾式"HIW"‘"HIB"百步穿杨"NOR+HIW"’"HIY"，"NOR
"飞箭狂出直逼 "HIY"$n"NOR" 的$l"HIY"，"NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       270,
                "force":        270,
                "damage_type": "射伤",
                "post_action":  (: god_att :),
        ]),
// 12
        ([      "action":
HIR" $N"NOR" 以朝 "HIY"$n"NOR" 连射三发$c"HIY"，"NOR"其意以欺敌而用"HIY"，"NOR
"骤时又发飞箭千许只"HIY"，"NOR"箭箭"HIW"势如破竹"HIY"，"NOR+HIW"骁勇难当"HIY"，"NOR
"顿时"HIR" $N"NOR" 以施以流星箭疾诀□"YEL"‘"HIY"杯弓蛇影"NOR+YEL"’"HIY"，"NOR
"箭势直冲 "HIY"$n"NOR" 的$l"HIY"，"NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       300,
                "force":        300,
                "damage_type": "射伤",
                "post_action":  (: shooting_att :),
        ]),
// 13
        ([      "action":
HIR" $N"NOR+HIW" 自持$w"HIY"，"NOR+HIW"萧然吟道："HIC"‘"HIY
"云笼月，风弄铁，两般儿，助人凄切"HIC"’"HIY"，"NOR+HIW"适时提出腰际间的$c"HIY
"，"NOR+HIW"傲然射出"HIY"，"NOR+HIW"风啸鹤唳"HIY"，"NOR+HIW"箭疾傲远"HIY"，"NOR
+HIW"此招正是流星箭疾诀□素招"HIG"‘"HIC"乘风归去"HIG"’"HIY"，"NOR+HIW"$c"HIW
"如影随形地直奔向 "HIY"$n"NOR+HIW" 的$l去"HIY"，"NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       300,
                "force":        300,
                "damage_type": "射伤",
                "post_action": (:shooting_att:),        
]),
// 14
        ([      "action":
HIR" $N"NOR" 直视 "HIY"$n"NOR" 之所在"HIY"，"NOR"并观风听闻以求箭准"HIY"，"NOR
"体内气劲直冲手臂"HIY"‘和阳、虞池’"NOR"两穴"HIY"，"NOR"顺其内功心法"HIY"，"
NOR"意入"HIW"乱石崩云，惊涛裂岸，卷起千堆雪"NOR"中之豪气"HIY"，"NOR
"手中之$c飞奔而出"HIY"，"HIR"箭拔弩张，疾风列啸"HIY"，"NOR"$c以惊人之势直往 "
HIY"$n"NOR" 的$l射去"HIY"，"NOR"此招正是流星箭疾诀□极至"HIW"‘"HIR"怒"RED"火"
HIR"辽"RED"原"NOR+HIW"’"HIY"，"NOR"箭势傲然狂飙"HIY"，"NOR"直射往 "HIY"$n"NOR
" 的$l处"HIY"，"NOR,
                "dodge":        -10,
                "parry":        -30,
                "damage":       300,
                "force":        300,
                "damage_type": "射伤",
        ]),
// 15
        ([      "action":
HIR" $N"NOR+HIW" 体会流星箭法中的"HIB"奥妙"HIY"，"NOR+HIW"手中握起$w"HIY"，"NOR
+HIW"瞬时取箭数十余只"HIY"，"NOR+HIW"缓缓念道："HIC
"「一点浩然气，千里快哉风。”"HIW"使出射日派武学中最高箭法"NOR" -- ",
                "dodge":        -10,
                "parry":        -30,
                "damage":       300,
                "force":        300,
                "damage_type": "射伤",
                "post_action": (: shooting_att :),        
]),
(["action":"你不是射手不能用其技能。",
"damage":10,
"damage_type": "白痴伤",
]),
});

// 下面是没箭时的攻击叙述

mapping *bow_action = ({
        ([      "action":               "$N举起$w狠狠地往$n$l砸去",
                "damage":       10,
                "damage_type":  "瘀伤",

        ]),
        ([      "action":               "$N吃力地挥舞$w试着打伤$n",
                "damage":       10,
                "damage_type":    "瘀伤",

        ]),
});

int valid_learn(object me)
{
        object ob;
        if(me->query_skill("archery",1)<15)
                return notify_fail("要练流星箭法要先有相当的弓箭基础。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type")!="archery")
                return notify_fail("你手上要有弓箭才能练流星箭法。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="archery" || usage=="parry";
}
string perform_action_file(string action)
{
        return CLASS_D("marksman")+"/god-shooting/"+action;
}

mapping query_action(object me, object weapon)
{
  int skill;
  object wpn = me->query_temp("weapon");
  int i;
  i=wpn->query("arrow/amount");
  if( !userp(me) ) i++;
  if(i==1) {
  tell_object(me, "\n你的" + wpn->query("arrow/name") + "用完了！\n\n");
  wpn->set("arrow/id","none");
  wpn->set("arrow/name","空的");
  wpn->set("weapon_prop/damage",wpn->query("bow/attack"));
  }
  if( i <= 0) { return bow_action[random(sizeof(bow_action))]; }
  else {
        i--;
        wpn->set("arrow/amount",i);
        skill = (int)me->query_skill("god-shooting", 1);
if(me->query("family/family_name")!="射日派") return arrow_action[15];
else if (skill < 7 ) return arrow_action[random(3)];
        else if (skill < 14 ) return arrow_action[random(4)];
        else if (skill < 21 ) return arrow_action[random(5)];
        else if (skill < 28 ) return arrow_action[random(6)];
        else if (skill < 35 ) return arrow_action[random(6)+1];
        else if (skill < 42 ) return arrow_action[random(7)+1];
        else if (skill < 49 ) return arrow_action[random(7)+2];
        else if (skill < 56 ) return arrow_action[random(8)+2];
        else if (skill < 63 ) return arrow_action[random(8)+3];
        else if (skill < 70 ) return arrow_action[random(9)+3];
        else if (skill < 77 ) return arrow_action[random(10)+3];
        else if (skill < 84 ) return arrow_action[random(11)+3];
        else if (skill < 91 ) return arrow_action[random(12)+3];
        else return arrow_action[random(12)+3];
        }
}

void upforce(object me, object victim, object  weapon, int damage)
{
     int skill = me->query_skill("force")/10;
     int bell = me->query("bellicosity")/300;
     int bell1 = random(me->query("bellicosity"));
     int bell2 = random(victim->query("bellicosity"));
     if( me->query("bellicosity") < 600 || damage < 0 ) return ;
     if( bell1 > bell2 ) {
     victim->add("bellicosity",-1* random(3));
     me->add("bellicosity",random(3));
     victim->add("force",-1 * random(me->query("bellicosity")/25));
     me->add("force",random(me->query("bellicosity")/25));
     }
if( !me->query_temp("upforce") && me->query("kee") > 5*bell && !me->query_temp("berserk") ) {
     message_vision(RED"\n\n$n"HIR"喷出的鲜血激起了"NOR+RED"$N"HIR"的疯狂杀意"HIY
     "～～！！"HIR"顿时"HIY"，"NOR+RED"$N的"HIB"狂杀之气"HIR
     "笼罩方圆十里之地"HIY"。\n\n"NOR, me, victim);
     me->set_temp("oldforce",me->query("force_factor"));
     me->add("force_factor",random(bell+skill/4));
     me->receive_wound("kee",5*bell);
     me->set_temp("upforce",1);
     me->start_busy(1);
     if(victim->query("bellicosity") < 0) victim->set("bellicosity",0);
     call_out("remove_upforce",skill,me);
     }
}
int remove_upforce(object me)
{
    me->set("force_factor",me->query_temp("oldforce"));
    me->delete_temp("oldforce");
    me->delete_temp("upforce");
    message_vision(HIW"\n$N"HIW"杀意渐渐消退"NOR"，"HIW
                   "脸上的杀意也没之前的沉重"NOR"。\n", me);
    return 1;
}
void god_att(object me, object victim, object  weapon, int damage)
{
if(50>random(100)&&!me->query_temp("berserk"))
{
victim->start_busy(1);
message_vision(HIB"$N暗使冰心诀之阴寒内劲，将$n受内劲所困动弹不得。\n"NOR, me, victim);

}
}

void shooting_att(object me,object *victim,object weapon,int damage)
{
         object *target;
       int i,j,k,l,m;
int bellpower = (int)me->query("cor")/5;
     int exp= me->query("combat_exp");
     if(exp >=0 && exp <=50000)
              l=1;
     if(exp > 50000 && exp <=100000)
              l=2;
     if(exp > 100000 && exp <= 500000)
              l=3;
     if(exp > 500000 && exp <=1000000)
              l=4;
     if(exp > 1000000 && exp <=1500000)
              l=5;
     if(exp > 1500000 && exp <=3000000)
              l=6;
     if(exp > 3000000 && exp <=4500000)
              l=7;
     if(exp > 4500000 && exp <=7000000)
              l=8;
     if(exp > 7000000 )
              l=9;
     m=random(5)+l;
        target=me->query_enemy();
         k=sizeof(target);
        if(k > 4)
       k=4;
  if(random(100)<50 && !me->query_temp("berserk"))
        {
                me->set_temp("berserk", 1);
                  for(i = 0;i < m; i++)
{
   for(j=0;j<k;j++){
        message_vision(HIR"$N拿起数支箭使劲的往$n连射过去 \n"NOR,me,target[j]);
        COMBAT_D->do_attack(me,target[j],me->query_temp("weapon"), TYPE_QUICK);
           COMBAT_D->report_status(target[j],1);
                       }
        }
      message_vision(HIW"一阵混乱后, $N用劲过度, 赶紧趁机调息 \n"NOR,me);
    me->start_busy(1);
             me->delete_temp("berserk");
}
}
