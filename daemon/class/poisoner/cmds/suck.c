#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;
inherit F_FUNCTION;
int main(object me,string arg)
{
object target;
string st1;
int lolo,fun;
int jojo;
int sk=me->query_skill("coldpoison",1);
fun=me->query("functions/suck/level");
jojo=me->query("poison");
lolo=me->query_skill("poisonforce",1);
if (!arg||sscanf(arg,"%s",st1)!=1)
return notify_fail("指令格式: suck <毒>\n");
if (!(target=present(st1,me)))
    return notify_fail("你的身上没有这种毒, 你要吸什么?\n");
if (!target->query("poison_type"))
    return notify_fail("你老眼昏花了呀!?这是毒吗?\n");
if (me->query_condition("poison") > 0 )
   return notify_fail("吸太急会要人命喔 !\n");
if(sk<60)
return notify_fail("你天冰奇毒还没练到一定等级多加油吧。\n");
message_vision(HIW"$N伸出右手, 运功吸纳了"+target->name()+"的毒性。\n"NOR,me);
me->add("poison",random(30));
me->apply_condition("poison",3+(int)(fun/10));  
target->add_amount(-1);
if(fun<100) function_improved("suck",random(700));
return 1;
}

int help(object me)
{
   write(@HELP

指令格式：suck <毒>

说明：这个指令可以让你吸收毒药中的毒性。

HELP
   );
   return 1;
}


