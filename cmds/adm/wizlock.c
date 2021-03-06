// wizlock.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }
int main(object me, string arg)
{
  int lvl;

  if( me!=this_player(1) ) return 0;
  if( wiz_level(me) <= wiz_level("(arch)") )
    return notify_fail("你的巫师等级太低，没有使用这个指令的权力。\n");
  if( !arg || arg=="" ) {
    write ("wiz lock level at : "+read_file("/include/lock.h")+"\n");
    return 1;
  }

  if( sscanf(arg, "%d", lvl)!=1 ) lvl = wiz_level(arg);
  if (lvl > wiz_level (me)) lvl = wiz_level (me);
  if (write_file("/include/lock.h",sprintf("%d",lvl), 1)) {
    write ("ok, lock to wiz_level "+ lvl + "\n");
    return 1;
  } else
    return notify_fail("上线权限设定失败。\n");
}

int help (object me)
{
        write(@HELP
指令格式: wizlock <巫师等级>
 
限制某个等级以下的使用者进入游戏。
其中巫师等级分别为：
	0 : player
	1 : immortal
	2 : apprentice
	3 : wizard
	4 : arch
	5 : admin
	6 : guest
	7 : manager
若要取消限制, 则输入 0.
 
HELP
);
        return 1;
}
 
