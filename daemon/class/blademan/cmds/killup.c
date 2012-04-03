// 提升杀气 by swy
#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;
int main(object me, string arg)
{
        int i;
        int be=me->query("bellicosity");
if(
me->query("id")=="sirius")
return notify_fail("没有这样指令。\n");
        if( !arg ||  !sscanf(arg, "%d", i) )
        return notify_fail("指令格式：cmd killup <杀气点数>\n");
        if(me->query_skill_mapped("force")=="fireforce")
        return notify_fail("只有用自身内功才能提升杀气。\n");
        if( be+i > 4000)
        return notify_fail("你所要提升的杀气加原杀气已过4000。\n");
        if( i*2 > me->query("force") )
        return notify_fail("你的内力不足以压制杀气。\n");
        if( i <= 0 )
        return notify_fail("你最少要提升一点。\n");
        if( me->query_temp("killup")==1 )
        return notify_fail("你正在运功中。\n");
        me->add("force",-i);
        message_vision(HIC"$N运起自身内功企图提升杀气。\n"NOR,me);
        me->start_call_out((:call_other, __FILE__, "bell_change",me,i:),2);
        me->set_temp("killup",1);
        return 1;
}
void bell_change(object me,int i)
{
    me->add("bellicosity",i);
    message_vision(YEL"$N的杀气提升了"+chinese_number(i)+"点。\n"NOR,me);
    me->delete_temp("killup");
    return ;
}

int help(object me)
{
    write(@HELP
 
指令格式： cmd killup <杀气值>□
 
说明：这个指令让你可以用内力转杀气,但上限为4000。
      例: cmd killup 10  加十点
 
HELP
);
     return 1;
}
