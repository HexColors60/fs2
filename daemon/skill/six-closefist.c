
//  six-closefist.c
#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void power(object me, object victim, object weapon, int damage);
void burn(object me, object victim, object weapon, int damage);
//void diyk(object me, object victim, object weapon, int damage);//
mapping *action = ({
 (["action":"$N���һ��,һ��"HIW"���� �� ͷ��"NOR"$N���һ�硢����һ��
����������ǿ�ҵĳ����$n����ȥ",
                  "dodge":     -40,
                  "parry":     -30,
                  "force":     130,
                  "damage":    60,
                  "damage_type":     "����",
                 ]),
 (["action":"$N����һ�࣬ʹ��һ��"HIY"����ţ��\ͷ��"NOR"$N�ҽ�����һ�磬ȭ��˳����$n�����һ��",
                  "dodge":     -40,
                  "parry":     -10,
                  "force":     130,
                  "damage":     65,
                  "damage_type":    "����",
            ]),
 (["action":"$N����һվ������ȫ������ʹ��һ��"HIB"��������ʯ��ӥ׽�ѡ�"NOR"$N����������$nһ������$n����֮ʱʹ���ƾ���$nһͷ����",
                  "dodge":     -50,
                  "parry":     -30,
                  "force":     130,
                  "damage":     70,
                  "damage_type":     "����",
                  "post_action":  (: burn :),
                 ]),
 (["action":"$N����ʹ������ȭ֮"HIC"��������ʯ��˫�ưѣ�˫�ѡ�"NOR"���ƾ����˳����$n����������������",
                  "dodge":     -50,
                  "parry":     -30,
                  "force":     130,
                  "damage":     80,
                  "damage_type":     "����",
                 ]),
 (["action":"$N����һ�ˡ�����һ��ʹ��һ��"HIG"�����ﳯ��������ɽ��"NOR"$N����ǰһ�磬ȭ����$n�¶�һ���Ż������ƾ���$nͷ��һ��",
                  "dodge":     -40,
                  "parry":     -30,
                  "force":     140,
                  "damage":     90,
                  "damage_type":     "����",
                  "post_action":  (: burn :),
                 ]),
 (["action":"$Nʹ����������ȭ֮"HIG"�����⣮���ﳯ����"NOR"$N˫��һ�̣���$n���ض���ȥ�����Է����ƾ���$n�¶���ȥ",
                "dodge":                -30,
                "parry":                -20,
                "force":                180,
                "damage":               100,
                "damage_type": "����",
                "post_action":  (: power :),
       ]),

 (["action":"$N����һ����һ������ȭ֮"HIM"�������Լ硯"NOR"$N��ϥ��$n�ĸ���һ��������ȭ��˳����$n����һ����ȥ",
                  "dodge":     -50,
                  "parry":     -30,
                  "force":     150,
                  "damage":     100,
                  "damage_type":     "����",
                "post_action":  (: power :),
                 ]),
 (["action":"$Nʹ������ȭһ��"HIB"�����ȣ������硯"NOR"$N�ž�������$n������������",
                "dodge":                -30,
                "parry":                -10,
                "force":                200,
                "damage":               110,
                "damage_type":  "����",
                "post_action":  (: power :),
                 ]),
 (["action":"$Nʹ������ȭ֮"HIR"���ߴ��ȣ���ţ��\ͷ��"NOR"$N�ҽ�΢�ߣ����Ի��ȭ����$nͷ��һ��",
                     "dodge":     -40,
                     "parry":     -10,
                     "force":     200,
                     "damage":    120,
                     "damage_type":    "����",
                     "post_action":  (: burn :),
       ]),
 (["action":"$Nʹ����������ȭ֮����"HIY"���Ʊ����°ѡ�"NOR"$N˫�ƽ�$n˫�ְ��£��Ż�����˫��˳����$n���¶���ز����ƹ�ȥ",
                     "dodge":     -40,
                     "parry":     -40,
                     "force":     200,
                     "damage_type":    "����",
                     "damage":    150,
                     "post_action":  (: burn :),
       ]),
 (["action":"$Nʹ����������ȭ֮����"HIY"���� �� �ѡ�"NOR"$N��$n�ַ��ְ�ס����
��ʵ�ļ粿����$n���ز�",
                     "dodge":     -40,
                     "parry":     -40,
                     "force":     200,
                     "damage":    160,
                     "damage_type":    "����",
                     "post_action":  (: burn :),
    ]),

});
void power(object me, object victim, object weapon, int damage)

{

int i;
 if(me->query("combat_exp") >= 600000 )
 if(me->query("force")>100&&me->query("force_factor"))

{
   for(i=1;i<=3;i++)
{
    switch(i)
{
case 1:
message_vision(sprintf(
HIC"$N�����˵Ĺ����߽����ʹ����������ȭ֮"HIY"��Ӳ����������"NOR"��"HIC"ֱȡ���˵�����Ҫ����\n"NOR),me);


message_vision(sprintf(
HIG"$N���ֽ�$n������ץס��ʹ�������ƾ���$n�ֹؽڴ���ȥ��ֻ����$n����һ����\n"NOR),me,victim);
break;
case 2:
message_vision(sprintf(
HIW"$N�����ۺ������˳����$n���ز�Ҫ���ݺݵĶ���ȥ��ֻ����$n�ҽ�һ����\n"NOR),me,victim);
break;
case 3:
message_vision(sprintf(
HIM"$N��˳���Է����ƾ���$n������һ�ģ���ʱ$nѪ��˲���$n�����ŲҲ��ܶá�\n"NOR),me,victim);
break;
}
     if(me->query_skill("six-closefist",1)>random(80))
{
message_vision(sprintf("�����$Nȷȷʵʵ������Ҫ����$n���������������ˡ�\n"),me,victim);
            victim->receive_wound("kee",80,me);
          COMBAT_D->report_status(victim, 1);
   me->add("force",-80);
}else{

message_vision(sprintf("���$N�Ĺ�����$n���ɱ��˿�����\n"),me,victim);
}
}
}
}
void burn(object me, object victim, object  weapon, int damage)
{
message_vision(HIM"$N�ľ���ʹ$n������Ѫ����Ƕ��ѣ�ʹ$n�ܵ������ص�����\n"NOR,me,victim);
         victim->apply_condition("burn",random(30));
         victim->receive_damage("kee",30);
         victim->add("force",-30);
         COMBAT_D->report_status(victim, 1);
 }

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                           return   notify_fail("��������ȭ������֡�\n");
        if(me->query("max_force")<100)
               return notify_fail("ι! С��, ��������Ҫ 100 ร����㳤���������\n");
        if(me->query_skill("snowforce",1)<10)
               return notify_fail("��������ķ���򲻹�����������������ȭ��\n");
        if(me->query_skill_mapped("dodge")=="six-closefist")
               me->map_skill("dodge","black-steps");
        return 1;

}

int valid_enable(string  usage)  {

        if(this_player()->query_skill("six-closefist",1) >= 50)
         {
            return (usage=="unarmed")||(usage=="parry");
         }
             return usage=="unarmed";
}



mapping query_action(object me, object weapon)

{
   int skill;
   skill=me->query_skill("six-closefist", 1);
   if( skill < 20)
      return action[random(3)];
   else if( skill < 40)
      return action[random(4)];
   else if( skill < 60)
      return action[random(5)];
   else if( skill < 80)
      return action[random(9)];
   else if( skill < 90)
      return action[random(10)];
   else
      return action[random(11)];

}

int practice_skill(object me)

{
        if( (int)me->query("kee") < 30 )
                      return  notify_fail("������������޷���ϰ��������ȭ��\n");
        if( (int)me->query("force") < 5 )
                   return  notify_fail("�������������������ϰ��������ȭ��\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}

string perform_action_file(string action)

{
        return CLASS_D("fighter")+"/six-closefist/"+action;
}

