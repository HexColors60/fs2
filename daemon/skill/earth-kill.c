#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void earthkill(object me,object victim,object weapon,int damage);
void killall(object me,object victim,object weapon,int damage);
void heartkill(object me,object victim,object weapon,int damage);
void threekill(object me,object victim,object weapon,int damage);
void skykill(object me,object victim,object weapon,int damage);
void bloodkill(object me,object victim,object weapon,int damage);
void burn(object me,object victim,object weapon,int damage);
void cold(object me,object victim,object weapon,int damage);

mapping *action = ({
(["action":"$N不是忍者所以无法使用。",
"dodge":0,
"parry":0,
"damage":0,
"damage_type":  "刺伤"
]),
(["action":HIW"$N东瀛伊贺流地斩十式第一式短刃技‘"HIR"空  蝉"HIW"’, 身型一晃, 手中兵器已经袭向$n弱点。"NOR,
"dodge":                 -40,
"parry":                 -40,
"damage":                100,
"force":                 100,
"damage_type":  "刺伤"
]),
(["action":HIW"$N东瀛伊贺流地斩十式第二式短刃技‘"HIR"山  岚"HIW"’, 稳健的攻击逼得$n手忙脚乱。"NOR,
"dodge":                -40,
"parry":                -40,
"damage":               110,
"force":                110,
"damage_type":  "割伤"
]),
(["action":HIW"$N东瀛伊贺流地斩十式第三式短刃技‘"HIR"冰  舞"HIW"’, 只见$N迅速的绕到$n身后准备给予致命的一击。"NOR,
"dodge":                -50,
"parry":                -50,
"damage":               120,
"force":                120,
"post_action":               (: cold :),
"damage_type":  "冻伤"
]),
(["action":HIW"$N东瀛伊贺流地斩十式第四式短刃技‘"HIR"炎  袭"HIW"’, 手中兵器如火焰般扑向$n。"NOR,
"dodge":                -50,
"parry":                -50,
"damage":               130,
"post_action":               (: burn :),
"damage_type":  "烧伤"
]),
(["action":HIW"$N东瀛伊贺流地斩十式第五式短刃技‘"HIR"血  杀"HIW"’, $n溅出的鲜血随风四处飘散。"NOR,
"dodge":                -60,
"parry":                -60,
"damage":               145,
"force":                145,
"post_action":               (: bloodkill :),
"damage_type":  "刺伤"
]),
(["action":HIW"$N左右晃动, 步法散中有序, 身影忽然消失在空气之间, 使出忍者至高武术之‘"HIR"灭  天  闪"HIW"’。"NOR,
"dodge":                -60,
"parry":                -60,
"damage":               150,
"force":                150,
"post_action":               (: skykill :),
"damage_type":  "刺伤"
]),
(["action":HIW"$N使出东瀛伊贺流地斩十式第七式短刃技‘"HIR"三  方  斩"HIW"’, 刀光四起, 四处鲜血飞溅。"NOR,
"dodge":                -60,
"parry":                -60,
"damage":               200,
"force":                200,
"post_action":               (: threekill :),
"damage_type":  "刺伤"
]),
(["action":HIW"$N激发全身杀气, 一招‘"HIR"破  心  击"HIW"’以凌人的霸气震摄$n。"NOR,
"dodge":                -70,
"parry":                -70,
"damage":               200,
"force":                200,
"post_action":               (: heartkill :),
"damage_type":   "刺伤"
]),
(["action":HIW"$N使出地斩奥义‘"HIR"撼  地  诀"HIW"’, 在极短的时间内朝着$n周身破绽进行猛攻。"NOR,
"dodge":               -70,
"parry":               -70,
"damage":              200,
"force":               200,
"post_action":               (: earthkill :),
"damage_type":               "刺伤"
]),        
(["action":HIW"$N如鬼魅般的迅速移动身型, 只见刀光一闪, 一招‘"HIR"瞬  杀  四  方"HIW"’朝着四周猛劈。"NOR,
"parry":             -70,
"dodge":             -70,
"damage":            250,
"force":             250,
"post_action":               (: killall :),
"damage_type":   "刺伤"
]),
});
int valid_enable(string usage)
{
return usage=="dagger" || usage=="parry";
}

mapping query_action(object me, object weapon, object victim, object *enemy,object room)
{
int skill_level, limit, i, j=0,kill_hurt;
skill_level=(int)me->query_skill("earth-kill", 1);
limit=(int)(skill_level/10);
enemy=me->query_enemy();
i=sizeof(enemy);
victim=enemy[random(i)];
kill_hurt=(me->query("earth-kill/killsword/exp"));
if (kill_hurt > 1500) kill_hurt=1500;
if (me->query_skill("earth-kill",1) > 90 && random(me->query("functions/manakee/level")) > 120
    && me->query_temp("earthkill")!=1)
{message_vision(HIG"
                       ～ ～  "HIR"秘 奥 义  "HIG"～ ～
                  "YEL"‘"HIB" 狂 乱 烈 风 之 空 蝉 地 斩 "YEL"’

               "HIM"真 ˙ 伊 贺 流 秘 义"HIW" －－"HIY"‘ "HIC"空    蝉 "HIY"’
                        
               "GRN"里 ˙ 伊 贺 流 奥 义"HIW" －－"HIY"‘"YEL" 地    斩 "HIY"’

"HIW"$N双奥义同时施展, 招式如狂风暴雨般的猛袭$n。\n"NOR,me,victim);
victim->receive_wound("kee",me->query_skill("force"));
victim->start_busy(1);
COMBAT_D->report_status(victim);
}
if (skill_level > 90 && random(100)>65 && me->query("bellicosity") > me->query("force")
    && me->query("bellicosity") > 8000 && me->query_temp("earthkill")!=1
    && me->query("quest/be_pker")==1 && me->query("force") > 1000)
{
me->do_command("hehe");
me->do_command("say 嘿嘿....就让你见识一下真正的杀人剑招!!");
message_vision(HIW"\n\t杀  人  剑 ～～～ "HIY"‘ 斩  人 ’ "HIW"!!\n"NOR,me);
victim->receive_wound("kee",kill_hurt/4);
COMBAT_D->report_status(victim);
me->add("force",-100);
me->add("bellicosity",-50);
if (me->query("bellicosity") > 13000)
{message_vision(HIW"\n\t杀  人  剑 ～～～ "HIC"‘ 斩  魂 ’ "HIW"!!\n"NOR,me);
victim->receive_wound("kee",kill_hurt/3);
me->add("force",-200);
me->add("bellicosity",-100);
COMBAT_D->report_status(victim);}
if (me->query("bellicosity") > 18000)
{message_vision(HIW"\n\t杀  人  剑 ～～～ "HIG"‘ 斩  鬼 ’ "HIW"!!\n"NOR,me);
victim->receive_wound("kee",kill_hurt/2);
me->add("force",-300);
me->add("bellicosity",-150);
COMBAT_D->report_status(victim);}
if (me->query("bellicosity") > 23000)
{message_vision(HIW"\n\t杀  人  剑 ～～～ "HIR"‘ 斩  神 ’ "HIW"!!\n"NOR,me);
victim->receive_wound("kee",kill_hurt);
me->add("force",-400);
me->add("bellicosity",-200);
COMBAT_D->report_status(victim);
COMBAT_D->report_status(victim);}
message_vision(HIB"\n招式过后, 天空洒下了一片腥红血雨 !!\n"NOR,me);
me->do_command("haha");
}
if (random(15000)< (me->query("cor")+me->query("cps"))+me->query("quest/add_bak")+me->query("earth-kill/bak/exp"))
{
message_vision(HIY"\n$N趁着$n短暂的疏忽, 给了$n致命的背刺!!\n\n"NOR,me,victim);
if (victim->query("max_kee")/2 > 100000)
{
room=environment(me);
tell_object(users(),HIW"一阵强烈能量从"+room->query("short")+"传出!!!!\n"NOR);
}
victim->receive_wound("kee",victim->query("max_kee")/2);
COMBAT_D->report_status(victim);
}
if (me->query("earth-kill/twoblade/exp") > 0 && me->query_temp("left_blade")==1
    && me->query_temp("right_blade")==1)
{
message_vision(HIW"\n$N使出二刀流双手短刃技之‘"HIR"双  刃"HIW"’, 只见$N迅速的朝着$n发动猛攻。\n"NOR,me,victim);
if (random(100)>20)
{message_vision(NOR"结果照成非常严重的刺伤。\n"NOR,me);
victim->receive_wound("kee",me->query("earth-kill/twoblade/exp"));
COMBAT_D->report_status(victim);}
else
{message_vision(NOR"但是被$N格开了。\n"NOR,victim);}
}
if (me->query("class") != "killer")
return action[0];
if (limit < 2 )
return action[random(2)+1];
if (limit == 2 )
return action[random(3)+1];
if (limit == 3 )
return action[random(4)+1];
if (limit == 4 )
return action[random(5)+1];
if (limit == 5 )
return action[random(6)+1];
if (limit == 6 )
return action[random(7)+1];
if (limit == 7 )
return action[random(8)+1];
if (limit == 8 )
return action[random(7)+2];
if (limit == 9 )
return action[random(7)+3];
else
return action[random(6)+5];
}
void earthkill(object me, object victim, object  weapon, int damage)
{
int cor,j=0;
cor=me->query("cor");
if (random(me->query("functions/manakee/level")) > 55-cor && me->query_temp("earthkill")!=1 
    && me->query("bellicosity") > 3000)
{
me->set_temp("earthkill",1);
for(j = 0;j < 5; j++)
{
COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
COMBAT_D->report_status(victim);
}
me->delete_temp("earthkill");
}
}
void killall(object me, object victim, object  weapon, int damage)
{
int i,hurt,j=0;
object *enemy;
enemy=me->query_enemy();
i=sizeof(enemy);
hurt=me->query("PKS")+600;
if (hurt > 1500) hurt=1500;
if (random(me->query("functions/manakee/level")) > 40 && me->query_temp("earthkill")!=1)
{
message_vision(HIW"只见$N在刀光中狂舞, 鲜血四处飞溅着!!\n"NOR,me);
for (j=0 ; j < i ; j++)
{
if (random(100) > 20)
{
message_vision(HIR"$N闪躲不及, 被刀光劈中, 鲜血狂喷!!\n"NOR,enemy[j]);
enemy[j]->receive_wound("kee",hurt);
me->add("force",-400);
COMBAT_D->report_status(enemy[j]);
}
else
{
message_vision(YEL"$N侧身一避, 躲开了这致命的一击!!\n"NOR,enemy[j]);
}}}}

void heartkill(object me, object victim, object  weapon, int damage)
{
int hurt;
me=this_player();
hurt=me->query("bellicosity")/25;
if (hurt > 800) hurt = 800;
if (random(me->query("functions/manakee/level")) > 80 && me->query_temp("earthkill")!=1 && me->query("force") > 500
    && me->query("bellicosity") > 500 )
{
message_vision(HIC"$N被$n散发出的强大气息震摄住, 全身无法动弹!!\n"NOR,victim,me);
victim->receive_damage("kee",hurt);
me->add("force",-300);
if (random(100) > 20 ) victim->start_busy(1);
me->add("bellicosity",-40);
}
}

void skykill(object me, object victim,object weapon,object *enemy)
{
int hurt;
me=this_player();
enemy=me->query_enemy();
hurt=me->query("bellicosity")/20;
if (hurt > 800) hurt = 800;
if (random(me->query("functions/manakee/level")) > 40 && me->query_temp("earthkill")!=1 && me->query("bellicosity")> 600)
{
message_vision(YEL"‘"HIB"临˙兵˙斗˙者˙皆˙阵˙列˙在˙前"YEL"’"HIW"～～$N口中默唸忍术九字真言!!\n"NOR,me);
message_vision(HIY"$N的兵器忽然洒出无数刀气朝向$n直攻而去, 只见$n闪避不及, 被$N的刀气击中。!!\n"NOR,me,victim);
victim->receive_wound("kee",hurt);
me->add("bellicosity",-30);
me->add("force",-200);
COMBAT_D->report_status(victim);
}}
void threekill(object me, object victim, object  weapon,object *enemy)
{
int i,hurt,k,j=0;
me=this_player();
enemy=me->query_enemy();
i=sizeof(enemy);
hurt=me->query("bellicosity")/25;
if (hurt > 250) hurt = 250;
if (random(me->query("functions/manakee/level")) > 50 && me->query_temp("earthkill")!=1 && me->query("bellicosity")> 600)
{
for (j=0 ; j < 3; j++)
{
message_vision(HIG"$N无声无息的绕到$n身候, 冷不防的在$n背后刺了一刀!!\n"NOR,me,victim);
victim->receive_wound("kee",hurt);
me->add("bellicosity",-20);
me->add("force",-50);
COMBAT_D->report_status(victim);
}
}}
void bloodkill(object me, object victim, object  weapon,object *enemy)
{
int str,cor,intt,spi,cps,per,con,kar,hurt;
me=this_player();
str=me->query("str");
cps=me->query("cps");
per=me->query("per");
con=me->query("con");
kar=me->query("kar");
intt=me->query("int");
cor=me->query("cor");
spi=me->query("spi");
hurt=(str+cor+intt+spi+cps+per+con+kar)*3;
if (random(me->query("functions/manakee/level")) > 40 && me->query_temp("earthkill")!=1 && me->query("bellicosity")> 600)
{
message_vision(HIR"$N吸取风中飘散的鲜血, 将血气纳为己用!!\n"NOR,me);
victim->receive_wound("kee",hurt);
me->receive_curing("kee",hurt);
me->receive_heal("kee",hurt);
me->add("bellicosity",-150);
me->add("force",-200);
COMBAT_D->report_status(victim);
}}
void burn(object me, object victim, object  weapon,object *enemy)
{
int hurt;
me=this_player();
hurt=me->query("functions/manakee/level")*3;
if (random(me->query("functions/manakee/level")) > 50 && me->query_temp("earthkill")!=1 && me->query("bellicosity")> 600)
{
message_vision(HIR"由$N杀意激发出来的炎劲不断侵袭$n!!\n"NOR,me,victim);
victim->receive_wound("kee",hurt);
victim->apply_condition("burn",10);
me->add("bellicosity",-25);
me->add("force",-100);
COMBAT_D->report_status(victim);
}}
void cold(object me, object victim, object  weapon,object *enemy)
{
int hurt;
me=this_player();
hurt=me->query("functions/manakee/level")*3;
if (random(me->query("functions/manakee/level")) > 50 && me->query_temp("earthkill")!=1 && me->query("bellicosity")> 600)
{
message_vision(HIC"由$N杀意激发出来的寒劲不断侵袭$n!!\n"NOR,me,victim);
victim->receive_wound("kee",hurt);
victim->apply_condition("cold",10);
me->add("bellicosity",-25);
me->add("force",-100);
COMBAT_D->report_status(victim);
}}
string perform_action_file(string action)
{
return CLASS_D("killer")+"/earth-kill/"+action;
}
int valid_learn(object me)
{
tell_object(me,"地斩无法从学习中获得进展, 必须自己修行方有成果!!\n");
return 0;
}
