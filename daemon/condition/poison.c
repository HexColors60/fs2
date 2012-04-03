#include <combat.h>
#include <ansi.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
  if(!me) return 0;
  if(!environment(me)) return 0;
   if(duration<=1) return 0; 
        if( duration > 3 ) {
                tell_object(me, HIB"你努力的将毒素纳入丹田。\n"NOR);
                message("vision", me->name() + "身上冰箔片片，正在行功险时。 \n",
                        environment(me), me);
        } else if( duration > 2 ) {
                tell_object(me, HIY"你行功渐缓，以吸收大半毒素。 \n"NOR);
                message("vision", me->name() + "似乎好多了 \n",
                        environment(me), me);
        } else if( duration > 1 ) {
                tell_object(me, "你终于将毒吸收完毕。 \n");
                message("vision", me->name() + "行功完成，恢复正常。 \n",
                        environment(me), me);
        }
     me->add("poison",5);
        me->apply_condition("poison", duration - 1);
        COMBAT_D->report_status(me, 1);
     if( duration <= 1 ) return 0;
        return 1;
}

