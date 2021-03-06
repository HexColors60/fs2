// bellup.c
//87.8.18更改回设定在永久SET上
//避免使用者离线又回来后
//TEMP值已经消失，而造成负值的情形
    
#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;

int main(object me, string arg)
{    
        int bell=me->query("bellicosity");
	int buf;

    buf=(int)(bell/200+1);
// 原因跟我在 bak.c 所说得一样不然只要赌的高
// 能爆无限 dodge So 设限不然太扯了 By Swy
// 因为战斗系统改了 attack 跟伤害力有关
// dodge and defense 跟抵销力有关
// 所以一定要设限
    if(buf > 100) buf = 100;
	me->set_temp("bellup_buf",buf);
        if(me->query("bellicosity")<200)
                return notify_fail("你身上的杀气不够。\n");
        if(me->query("force")<buf)
                return notify_fail("你的内力不够。\n");
        if(me->query("bellup")==1)
                return notify_fail("你现在正在放出杀气。\n");
        if(me->query("class")!="killer")
                return notify_fail("这样指令只有杀手才能用。\n");
        me->apply_condition("bell",(int)(bell/500)+5);
        me->add_temp("apply/damage",buf);
        me->add_temp("apply/attack",buf);
        me->add_temp("apply/dodge",buf);
        me->set("bellup",1);
        me->add("force",-buf);
        message_vision(
        HIG "$N大暍一声，放出身上的杀气，眼神由温和转变成恐怖。\n" NOR,me);
        return 1;
}

int help(object me)
{
    write(@HELP

指令格式：bellup

说明：这个指令让你可以将体内的杀气放出。

HELP
);
     return 1;
}

