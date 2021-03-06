// 本命令由容器搬过来，以减少记忆体的量
// 此外，由于中文化，外加说明档，以及以前喝水常常当机等,
// 希望这种改法会减少当机的可能.
// by wade in 1996 5 31
 
#include <ansi.h>
inherit F_CLEAN_UP;
 
int help ();
 
int main (object me,string arg)
{
  object env,can;
  mapping attr;
 
  seteuid(geteuid(me));
 
  if (!arg) return help();
  if (!objectp(can=present(arg,me))) return help();
 
  if (this_player()->is_busy())
    return notify_fail("你上一个动作还没有完成。\n");
 
  env = environment(me);
  if (!mapp(attr = env->query("资源/液体")))
    return notify_fail("找不到任何液体可以装.\n");
 
  if (env->query("have_poison"))
  {
    can->set ("get_poison",  env->query("poison_type"));
    can->set ("poison_power",env->query("poison_power"));
  }
 
  if (can->query("液体/剩"))
    message_vision("$N将" + can->name() + "里剩下的" +
                can->query("液体/名称") + "倒掉。\n",me);
 
  message_vision ("$N将" + can->name() + "装满" + attr["名称"]+"。\n",me);
 
  if (me->is_fighting()) me->start_busy(2);
 
  can->set("液体/种类",attr["种类"]);
  can->set("液体/名称",attr["名称"]);
  can->set("液体/剩",can->query("饱和"));
  can->set("液体/止渴",attr["止渴"]);
 
  return 1;
}
 
int help()
{
        write(@HELP
指令格式 : fill <容器名称>
 
指令说明 :
        本命令可以用来将容器装上溶液，如装水，装酒等等,
        当然，附近要有液体可以装才行，如水缸，水池，或湖泊等。
HELP
    );
    return 1;
}
