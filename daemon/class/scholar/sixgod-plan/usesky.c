//By sueplan取走敌人的weapon - 运天行道 2000.7.27
#include <ansi.h>
inherit SSERVER;
object me=this_player();
int perform(object me, object target)
{
        if( me->query("force") < 1000 )
        return notify_fail("以你的内力不足以用此计。\n");
        if( target != me)   
        return notify_fail("此计只能对自己用。\n");
        if( me->is_fighting() )
        return notify_fail("战斗中不能使用。\n");
        if( me->query_temp("usesky") == 1 )
        return notify_fail("天时地利人合已经被你掌握住了。\n");
message_vision(HIC"$N以六韬奇略中的观星说文之计，将自己立于不败之地。\n"NOR,me);
message_vision(HIC"$N感到自己刺术技巧又更上一层了。\n"NOR,me);
        me->add_temp("apply/stabber",30);
        me->set_temp("usesky",1);
        me->add("force",-500);
        return 1;
}




