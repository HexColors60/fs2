// look.c
// 同时考虑 灯光, 隐形, 巫师可多看档名

#include <room.h>
#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int do_search_ob(object me, object env);
int do_search_item (object env, string item);

int main(object me, string arg)
{
  object	obj, env;
  int		can_see;

  if (!can_see = NATURE_D->vision(me))
    return notify_fail ("现在四周乌漆妈黑的, 什么也看不到.\n");

  env = environment(me);
  
  if ( !arg )
    return do_search_ob(me, env);
  arg = lower_case(arg);

  if ( (obj = present(arg, me)) || (obj = present(arg, env))) {
    return do_search_ob (me, obj);
  }
  else {
    return do_search_item(env, arg);
  }
}

int do_search_item (object env, string item)
{
  mapping       search_desc;
  string        *search_item;
  int           n;

  search_desc = env->query("search_desc/"+item);
  if (!search_desc)
    return notify_fail ("你找了老半天，可是看不出有任何特殊之处。\n");
  write (search_desc);
  return 1;
}

int do_search_ob(object me, object env)
{
  mapping	search_desc;
  string	*search_item, msg;
  int		n;

  search_desc = env->query("search_desc");
  if (!search_desc || (n = sizeof (search_desc)) == 0)
    return notify_fail ("你找了老半天，可是看不出有任何特殊之处。\n");
  search_item = keys(search_desc);
  write ("你找了找, 发现 "+search_item[random(n)]+" 怪怪的。\n");
  return 1;
}

int help (object me)
{
	write(@HELP
指令格式 : search [<物品>|<生物>]
指令说明 : 
           这个指令让你搜寻你所在的环境、某件物品、生物。
HELP );
	return 1;
}
