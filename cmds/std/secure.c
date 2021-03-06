// wade 2002-10-23 加入 secure 可以 autoload 三件物品
inherit F_CLEAN_UP;
int help (object me);
 
int main(object me,string arg)
{
  object        *ob, obj;
  int           i, n;

#ifdef SAVEEQ
  int		autoload;
#endif
 
  if (!arg) return help(me);

  ob = all_inventory(me);
  n = sizeof (ob);

#ifdef SAVEEQ
  for (i=0; i<n; i++)
    if (ob[i]->query_autoload()) autoload++;
  autoload=0;
#endif

  if (arg == "all") {
    for (i=0; i<n; i++) {
      ob[i]->set_temp("secured", 1);
#ifdef SAVEEQ
      if (ob[i]->query("equipped")) {
        if (autoload < 3 && !ob[i]->query_autoload()) {
          ob[i]->set("autoload", 1);
          autoload++;
        }
      }
#endif
    }
  }
 
  else if (obj = present(arg, me)) {
#ifdef SAVEEQ
    if (autoload < 3 && obj->query("equipped") && !obj->query_temp ("secured"))
      obj->set ("autoload", 1);
#endif

    obj->set_temp("secured",1);
  }
  else return notify_fail ("没有这样物品。\n");
  return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式 : secure <物件>
范    例 : secure map
           secure all
说    明 :
           本指令让玩家可以保护物件，以免被 drop，sell，give
HELP
    );
    return 1;
}
