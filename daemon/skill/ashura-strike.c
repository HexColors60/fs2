//���ް�ȭ(Ashura-rike) Edit by del
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":       
"$Nʹ�����ް�ȭ��һʽ"HIR"��ɱ��"NOR"�����²���Խ��Խ�죬��$n�޷�׽����"
"ֻ��$N��˫ȭ��Ѹ�ײ����ڶ����ٶȹ���$n",
                "damage":80,
                "dodge":10,
                "damage_type": "����"
        ]),
        ([      "action":       
"$N����һ������������ע��ȭͷ��ʹ�����ް�ȭ�ڶ�ʽ"HIB"���ơ�"NOR"��ǿ��"
"����ȭ������ɽ����֮�ƻ���$n��$l",
                "damage":80,
                "dodge":20,
                "damage_type": "����"
        ]),
        ([      "action":       
"$N�����ھ�������Ϊ�У�˳��ʹ�����ް�ȭ����ʽ"HIB"����"NOR"����������"
"��ˮ��к�ذ�Ӹ������򹥻�$n",
                "damage":100,
                "dodge":10,
                "damage_type": "����"
        ]),

        ([      "action":
"$N�����ް�ȭ����ʽ"HIR"������"NOR"�������������������Լ���˫ȭ֮�ϣ���"
"��$n���֮�ʣ�����ĵĹ�������Ѹ�׼���㹥��$n",
                "damage":100,
                "dodge":10,
                "damage_type": "����"
        ]),

        ([      "action":
"$N��ȫ��ɱ���ͷţ�ʹ�����ް�ȭ����ʽ"HIR"���ϡ�"NOR"���ں�����ɱ���ȭ"
"�ƾ���һ�ѷ����ľ��а�Ҫ��$n����ն��",
                "damage" : 150,
                "dodge"  :  10,
                "damage_type" : "����"
        ]),

});

int valid_enable(string usage)
{
        return (usage=="unarmed") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
