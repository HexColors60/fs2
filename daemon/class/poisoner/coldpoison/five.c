#include <ansi.h>
inherit F_FUNCTION;
inherit SSERVER;
int fun;
int perform(object me, object target)
{
	string msg;
	object ob;
if(me->is_fighting()) { target = offensive_target(me);
} else { if(!target) return notify_fail("你要打谁？\n"); }
    if(target==me) return notify_fail("攻击自己???找死吗?\n");
	if(!(ob=present("five poison",me)))
	return notify_fail("你的身上没有五毒。\n");
	if( environment(me)->query("no_fight") )
	return notify_fail("这里不准战斗。\n");
if(target->query_temp("five-1")==1)
return notify_fail("对特定人物只能用一次。\n");
        if(me->query("family/family_name")!="冥蛊魔教")
        return notify_fail("你不是魔教徒。\n");
        if(me->query_temp("is_five"))
        return notify_fail("你正在使用。\n");
        msg=HIC "$N吸纳五毒，聚精会神伺机而动。\n"NOR;
        message_vision(msg, me);
	ob->add_amount(-1);
        me->set_temp("is_five",1);
    call_out("act1",5,msg,target,me);  
        return 1;
}
int act1(string msg,object target,object me) {
if(!me) return 1;
fun=me->query("functions/five/level");
me->delete_temp("is_five");
if(!target) return notify_fail("可能是精神错乱的缘故,你发现你竟然找不到敌人!!\n");
if(environment(me)!=environment(target))
return notify_fail("敌人不在这。\n"); 
if(!target) return notify_fail("敌人不见了。\n");
if(!living(target)) return notify_fail("敌人以死了。\n"); 
        if(80>random(100))
	{
        msg=HIR "$N见机「碰”的一声，$n身上已留下一个黑掌印。\n" NOR;
        target->apply_condition("five_poison",5);
    target->set("five",me->query("functions/five/level"));   
if(target->query("id")=="degu sa") target->set_temp("five-1",1);
        target->kill_ob(me);
        me->kill_ob(target);
} else msg= HIG "$N见机「碰”的一声，$n见情势危急，急防躲开。\n"NOR;
message_vision(msg, me, target);
if(fun<100) function_improved("five",random(700));   
return 1;
}
