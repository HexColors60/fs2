// by airke
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

string reattack();

string *dodge_msg=({
      "$nʹ��׷�ǲ��еġ�"HIW"���ľ�"NOR"�����û���������Ӱ��$N�����������ڿ���֮��....\n",
      "$n�������������ǡ����ǻ�λ��������˲ʱ�ƶ������˿�ȥ��\n",
      "$n����ȫ��������Ʈ�縡Ƽ�������ǻ�����бб������������\n",
"$n��ת���������ȡ����\��������һ˲���ѵ���$N�ı���\n",
      "$n���Ų�æ��ʹ����"HIB"׷�����ǲ�"NOR"��һ����������������뿪$N�Ĺ�����Χ��\n",
"$nʹ����"HIC"����Խ��"NOR"�������Ṧ������һԾ������ǿ��С�\n",
// (: reattack :),
    });

string reattack()
{
	object me , target;
	int react;
	string msg;
	me=this_player();
        react = (me->query_skill("g-steps",1) / 4) +5;
	target = offensive_target(me);
	target->receive_damage("kee",react);
	msg = me->query("name") + "ʹ��һ��" + HIR "��תǬ��" NOR + "��" +
	target->query("name") + "������ȥ��\n";
	return msg;
}	

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
  return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_enable(string usage) 
{
  return usage == "dodge" || usage == "move";
}


int practice_skill(object me)
{
	if( (int)me->query("gin") < 30 )
		return notify_fail("��ľ�������������׷�ǲ�����\n");
	me->receive_damage("gin", 30);
	return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("taoist")+ "/g-steps/" +action;
}