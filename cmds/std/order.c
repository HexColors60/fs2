// 重新改写 order by swy
inherit F_CLEAN_UP;
#include <ansi.h>
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
string dest,cmd,verb,act;
object ob;
if( me != this_player(1) ) return 0;
if( me->query("class")!="blademan" )
return notify_fail("你不是刀客无法驾御马。\n");
if( me->query_skill("riding",1) < 70 )
return notify_fail("你的马术太低，不能控制马唷。\n");
if( me->query_temp("is_riding") != 1 )
return notify_fail("你没骑马如何能驾御马呢？\n");
if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
return notify_fail("指令格式 : order <马马> to <动作>\n");
if( !(ob = present(dest, environment(me))) )
return notify_fail("这里没有 "+dest+"。\n");
if( !living(ob) )
return notify_fail("等你的马醒吧。\n");
if(me->query("id") != ob->query_temp("my_boss"))
return notify_fail("别傻啦，牠又不是你的马。\n");
if(sscanf(cmd,"%s %s",verb,act)) {
if(verb=="save"||
verb=="do"||verb=="wield"||verb=="set"||verb=="join") 
return notify_fail("没有这种指令！\n");
}
if(cmd[0..3]=="quit") return notify_fail("没有这种指令！\n");   
if(cmd[0..3]=="save") return notify_fail("没有这种指令！\n"); 
if(cmd[0..3]=="join") return notify_fail("没有这种指令！\n");
if(cmd[0..3]=="team") return notify_fail("没有这种指令！\n");   
message_vision(HIC"$N用马术驾御马儿，达到人马合一！\n"NOR,me);
message_vision(HIC"马儿听到指挥而作出"+cmd+"的动作。\n"NOR,me);
ob->force_me(cmd);
if(verb=="k"||verb=="ki"||verb=="kil"||verb=="kill"||
verb=="f"||verb=="fi"||verb=="fig"||verb=="figh"||verb=="fight")
{ me->force_me(cmd); } 
return 1;
}

int help(object me)
{
write(@Help

指令格式 : order <马马> to <动作>

能驾御马马的指令须要马术 70 级

Help);
return 1;
}
