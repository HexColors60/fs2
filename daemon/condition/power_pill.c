#include <ansi.h>
int update_condition(object me, int duration,int j)
{
     if(duration==1) 
     {  
     message_vision(HIC"$N身上蓝龙精元的效力已经消失!!\n"NOR,me);
     me->add_temp("apply/force",-25);
     return 0;
     }
     me->apply_condition("power_pill",duration-1);
     message_vision(HIC"蓝龙精元的效力慢慢在$N身上蔓延!!\n"NOR,me);
     if( duration < 1 )
     return 0;
     return 1;
}
