#include <ansi.h>
int update_condition(object me, int duration)
{
     if(duration==0) return 0;
      me->start_busy(1);
      me->apply_condition("hellthunder",duration-1);
      message_vision(HIC"$N受到九天真雷雷侵袭，全身麻木无法动弹!!\n" NOR,me);
        if( duration < 1 ) return 0;
        return 1;
}
