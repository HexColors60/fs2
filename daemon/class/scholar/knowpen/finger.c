//����һ��Сbug����ָ����ץ�������˻����ճ���
//ϣ����������Ա��������� by Neverend
#include <ansi.h>
#include <combat.h>
inherit F_FUNCTION;
inherit SSERVER;
int fun;
int perform(object me,object target)
{
	object weapon;
	int k1,k2,k3;
	if( !target ) target = offensive_target(me);
	if( !target)	return notify_fail("û�е��ˣ����˭ѽ!!\n");
	fun=me->query("functions/finger/level");
	if( me->query("family/family_name") != "����")
	return notify_fail("���Ż�ָ�����걲���ܿ��Ƶ��˵�...\n");
	if(!me->is_fighting(target))
	return notify_fail("���Ż�ָֻ����ս����ʹ�á�\n");
	if(!(weapon=me->query_temp("weapon")) || (string)weapon->query("skill_type")!="stabber" )
	return notify_fail("Ҫ���ʺϵ��������������Ż�ָ��\n");
	if(me->query("force") < 100)	return notify_fail("�������������\n");
	me->add("kee",-50);
	me->add("force",-100);
        message_vision(
""HIW"$NͻȻ����ʽ�еı仯������������ˮ�ʷ������հ���
"HIR" ==================================================
 ==============   "HIM"��   ��   ��   ָ "HIR" ==============
 ==================================================\n"
NOR,me,target);
	if( 80 > random(100))
	{
	message_vision(
""HIC"$n�޷��������Ż�ָ������������ָ��������$n�ľ����ɢ��\n"
NOR,me,target);
	k1=target->query("max_gin")/5;
	k2=target->query("max_kee")/5;
	k3=target->query("max_sen")/5;
	if(k1>300) k1=300;
	if(k2>500) k2=500;
	if(k3>300) k3=300;
	target->receive_damage("gin",(fun*4+k1));
	target->receive_damage("kee",(fun*8+k2));
	target->receive_damage("sen",(fun*4+k3));
	}else{
	message_vision(
""HIC"$n��͸�˻�ָ�о���ı仯���պô�$n���߲�����\n"NOR,me,target);
	}
	if(fun<100)
	function_improved("finger",random(500));
    me->start_busy(1);
	return 1;
}
