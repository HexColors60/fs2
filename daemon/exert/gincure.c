// 给基本 force
#define ALLOW ({"doctor","dancer"})
#include <ansi.h>
int exert(object me, object target)
{
	int power;
	if( (int)me->query("force") < 30 )
		return notify_fail("你的内力不够。\n");
	if( me->is_fighting() || target->is_fighting() )
		return notify_fail("战斗中无法凝神疗伤。\n");
	if( member_array(me->query("class"), ALLOW) == -1 )
		return notify_fail("你的职业无法凝神疗伤。\n");
        power = 5 + (int)me->query_skill("force")/10;
    if(!target) target=me;
	if( target==me ){
message_vision(HIC"$N盘腿而坐，连运内息之后，精力充足。\n"NOR, me);
	}
	else{

message_vision(HIC"$N运行全身内力帮助$n凝气疗伤，几个内息之后，$n已慢慢精力充足起来。\n"NOR, me, target);
                power = power/2;
	}
        target->receive_curing("gin", power );
	me->add("force", -power/2);
	return 1;
}
