// finger.c
#include <ansi.h>

#define INFO "/data/info/"
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
  object ob, body;
  int    r=0;

  if (arg) arg = lower_case(arg);

  if( !arg )
    return notify_fail("fingers <人名>\n");
  if ( !(ob = find_player(arg)) ) {
    ob = new(LOGIN_OB);
    ob->set("id", arg);
    if ( !ob->restore() )
      return notify_fail ("没有这个玩家。\n");
    body = LOGIN_D->make_body(ob);
    if (body->restore()) ob = body;
    else return notify_fail (arg+" 的档案出问题了, 请检查看看.\n");
    r = 1;
  }
  "/cmds/std/score"->wiz_score(ob);
  if (r) destruct(ob);
  return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : fingers [使用者姓名]
 
HELP
    );
    return 1;
}
