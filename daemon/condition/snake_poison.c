#include <ansi.h>
int update_condition(object me, int duration)
{
        if(duration==0) return 0;
	me->receive_damage("kee", 30);
	me->receive_damage("sen", 30);
        me->start_busy(2);
	me->apply_condition("snake_poison", duration - 1);
	tell_object(me, HIG "你中的蛇毒发作了！\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}
