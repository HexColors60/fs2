#include <ansi.h>
// By Swy 最后修正 QC 98/6/20
int perform(object me,object target)
{
	if( me->query("sen") < 10 )
		return notify_fail("你的精神不够，无法使用。\n");
        if( me->query_skill("plan",1) < 60 )
		return notify_fail("你的谋略程度不够。\n");
	if( !target ) return notify_fail("你要对谁用计 ?\n");
	if(me->is_fighting(target))	
		return notify_fail("奇袭之计只能在战斗前使用。\n");
  if( environment(me)->query("no_fight")==1 )
  return notify_fail("这里不准战斗。\n");
if( userp(target) && target->query("age")<16)
    return notify_fail("不能对未满16岁奇袭喔。\n");
  if(target->query("no_speed")==1)
  return notify_fail("奇袭对他无效！\n");
   if( target->query_temp("speed")==1 )
                return notify_fail("相同的计策对同一个人没有效。\n");
	me->add("sen",-15);
// 不是儒门
   if( me->query("family/family_name") != "儒门")
    return notify_fail("不是儒生，不给你用咧！！^_^\n");
    me->start_busy(1);
	message_vision( RED + @LONG
$N突然地对$n发动奇袭，杀得$n措手不及！
LONG + NOR , me , target );
	if(me->query_temp("invis")==1)
	{
        me->delete_temp("invis");
target->set_temp("speed",1);
target->start_busy(4);
        me->kill_ob(target);
        target->kill_ob(me);
	}
	else
        target->start_busy(3);
        target->set_temp("speed",1);
	me->kill_ob(target);
	target->kill_ob(me);
	return 1;
}

