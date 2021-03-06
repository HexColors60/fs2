#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void berserk(object me,object victim,object weapon,int damage);
void killall(object me,object victim,object weapon,int damage);

mapping *action = ({
(["action":"$N不是忍者所以无法使用。",
"dodge":0,
"parry":0,
"damage":0,
"damage_type":  "刺伤"
]),
(["action":HIW"$N抓住时机, 以迅雷不及掩耳的速度攻击$n周身三处要害。"NOR,
"dodge":-20,
"parry":-20,
"damage":30,
"damage_type":  "刺伤"
]),
(["action":"$N使出居合十式第二式刀技‘后’。",
"dodge":                -20,
"damage":               40,
"damage_type":  "割伤"
]),
(["action":"$N使出居合十式第三式刀技‘受  流’。",
"dodge":                -30,
"damage":               20,
"damage_type":  "割伤"
]),
(["action":"$N使出居合十式第四式刀技‘柄  当’。",
"dodge":                -40,
"damage":               50,
"damage_type":  "刺伤"
]),
(["action":"$N使出居合十式第五式刀技‘架  裟  切’。",
"dodge":                -40,
"damage":               45,
"damage_type":  "刺伤"
]),
(["action":"$N使出居合十式第六式刀技‘诸  手  突’。",
"dodge":                -20,
"damage":               50,
"damage_type":  "刺伤"
]),
(["action":"$N使出居合十式第七式刀技‘三  方  切’。",
"dodge":                -20,
"damage":               55,
"damage_type":  "刺伤"
]),
(["action":"$N使出居合十式第八式刀技‘颜  面  当’。",
"dodge":                -30,
"damage":               60,
"damage_type":  "割伤"
]),
(["action":"$N使出居合十式第九式刀技‘添  手  突’。",
"dodge"      :               -35,
"parry"      :               -45,
"damage"     :                90,
"force"      :                220,
"post_action":               (: berserk :),
"damage_type":               "刺伤"
]),        
(["action":HIW"$N如鬼魅般的迅速移动身型, 只见刀光一闪, 一招‘"HIR"瞬  杀  四  方"HIW"’朝着四周猛劈。"NOR,
"parry":             -60,
"dodge":             -60,
"force":          400,
"damage":         450,
"post_action":               (: killall :),
"damage_type":   "刺伤"
]),
});
int valid_enable(string usage)
{
return usage=="dagger" || usage=="parry";
}

mapping query_action(object me, object weapon, object victim, object *enemy)
{
int skill_level, limit, i, j=0,kill_hurt;
skill_level=(int)me->query_skill("japan-blade", 1);
limit=(int)(skill_level/10);
enemy=me->query_enemy();
i=sizeof(enemy);
victim=enemy[random(i)];
kill_hurt=(me->query("PKS"))*5;
if (kill_hurt > 1500) kill_hurt=1500;
if (skill_level > 90 && random(100)>1 && me->query("bellicosity") > me->query("force")
    && me->query("bellicosity") > 8000)
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
me->do_command("hehe");
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
return action[random(9)+1];
if (limit > 8 && limit < 10)
return action[random(5)+5];
else
return action[random(4)+7];
}
void berserk(object me, object victim, object  weapon, int damage)
{
int i;
if(!me->query_temp("berserk" ))
{
me->set_temp("berserk", 1);
for(i = 0;i < 10; i++)
{
message_vision(HIC"测试....杀杀!!!。\n"NOR, me, victim);
victim->add("kee",0);
me->add("force",0);
COMBAT_D->report_status(victim);
}
me->delete_temp("berserk");
message_vision(HIW"测试完毕。\n"NOR,me);
}
}
void killall(object me, object victim, object  weapon, int damage)
{
int i,hurt,j=0;
object *enemy;
me = this_player();
enemy = me->query_enemy();
i=sizeof(enemy);
hurt=me->query("PKS");
message_vision(HIW"只见$N在刀光中狂舞, 鲜血四处飞溅着!!\n"NOR,me);
for (j=0 ; j < i ; j++)
{
if (random(100) > 20)
{
message_vision(HIR"$N闪躲不及, 被刀光劈中, 鲜血狂喷!!\n"NOR,enemy[j]);
enemy[j]->receive_wound("kee",hurt);
COMBAT_D->report_status(enemy[j]);
}
else
{
message_vision(YEL"$N侧身一避, 躲开了这致命的一击!!\n"NOR,enemy[j]);
}
}
} 
