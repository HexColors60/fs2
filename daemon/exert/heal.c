// 给基本 force
#define ALLOW ({"fighter","bonze","prayer","doctor"})
int exert(object me,object target)
{
	int power;
int max=me->query("max_kee",1);
int maxt;
if(target)
maxt=target->query("max_kee",1);
	if( (int)me->query("force") < 30 )
		return notify_fail("你的内力不够。\n");
	if( me->is_fighting() || target->is_fighting() )
		return notify_fail("战斗中无法疗伤。\n");
    if( member_array(me->query("class"), ALLOW) == -1 && !wizardp(me))
		return notify_fail("你的职业无法疗伤。\n");
if(me->query("eff_kee")==max && !target)
return notify_fail("你没有受伤。\n");
if(target)
  if(target->query("eff_kee") >= maxt)
    return notify_fail(target->query("name")+"没有受伤\n");
      if(me->query_condition("mogi"))
        return notify_fail("[1;32m身上的入灭之毒忽然发作,使内息受到影响无法运气疗伤[0m\n");
       if(target->query_condition("mogi"))
        return notify_fail("[1;32m对方身上的入灭之毒,使你无法帮他运气疗伤[0m\n");
        power = 5 + (int)me->query_skill("force")/10;
	if( target==me ){
		message_vision("[36m$N盘腿席地而坐，运行全身内力疗伤，一阵白气从$N头顶冒出后, 伤势已慢慢转好。[0m\n", me);
	}
	else{
		message_vision("[36m$N盘腿席地而坐，运行全身内力帮助$n疗伤, 一阵白气从头顶冒出后, $n伤势已慢慢转好。[0m\n", me, target);
                power = power/2;
	}
        me->receive_curing("kee", power );
    if(target)
      if(target != me) target->receive_curing("kee",power);
	me->add("force", -30);
	return 1;
}
