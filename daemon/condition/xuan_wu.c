#include <ansi.h>
int i;

int update_condition(object me,int duration)
{
	if( duration >= 1 )
	{
		tell_object(me,HIB"\n丹田气如龟息!!渐缓待滞...\n"NOR);

		if( me->query("/open/forest/clear_xuan_wu") )
		{
			me->delete("/open/forest/clear_xuan_wu");
			me->clear_condition("xuan_wu");
			tell_object(me,HIC"魄壳之术产生效用，一股真气直抵丹田，冲破龟息!!\n\n"NOR);
		}

		else 
		{
			tell_object(me,HIB"你意识渐渐失去，身体不受控制...\n\n"NOR);
			i = random(3)+1;
			me->start_busy(i);
		}
	}

		if( duration < 1 )
			return 0;
	return 1;
}
