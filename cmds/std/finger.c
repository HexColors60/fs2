// finger.c
#include <ansi.h>
 
#define INFO "/data/info/"
inherit F_CLEAN_UP;
 
void create()
{
        seteuid(getuid());
}
 
int main(object me,string arg)
{
string msg;
 
  if (arg) arg = lower_case(arg);
 
  if (wizardp (me)) {
    if( !arg )
      me->start_more( FINGER_D->finger_all() );
    else {
      msg = FINGER_D->finger_user(arg);
      me->start_more(msg);
    }
  }
  else {
        if( !arg ) {
                if( (int)me->query("sen") < 30 )
                        return notify_fail("你的精神无法集中。\n");
                me->receive_damage("sen",30);
                write( FINGER_D->finger_all() );
        } else {
                if( (int)me->query("sen") < 15 )
                        return notify_fail("你的精神无法集中。\n");
                me->receive_damage("sen",15);
                write( FINGER_D->finger_user(arg) );
        }
  }
        return 1;
}
 
int help(object me)
{
  write(@HELP
指令格式 : finger [使用者姓名]
指令说明 :
           这个指令，如果没有指定使用者姓明，会显示出所有
         正在线上玩家的连线资料。反之，则可显示有关某个玩
         家的连线，权限等资料。
其他参考 :
           who
HELP
    );
    return 1;
}
