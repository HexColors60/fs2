// 本命令由容器搬过来，以减少记忆体的量
// 此外，由于中文化，外加说明档，以及以前喝水常常当机等,
// 希望这种改法会减少当机的可能.
// by wade in 1996 5 31

#include <ansi.h>
inherit F_CLEAN_UP;
 
int help (object);

int main (object me,string arg)
{
  object can;
  mapping my;

  seteuid(getuid(me));
 
  if (!arg) return help(me);
  if (!objectp(can=present(arg,me))&&
      !objectp(can=present(arg,environment(me))))
    return help(me);

  my = can->query("液体");

  // 可以在容器上头设定额外函数
  if (can->query("液体/额外函数")) return 1;

  if( !can->query("液体/剩") ) {
    if (stringp(can->query("液体/名称")))
      printf ("%s的%s已经被喝光了。\n",can->name(),can->query("液体/名称"));
    else
      printf ("%s是空的。\n",can->name());
    return 1;
  }

  if (me->query("water") >= me->max_water_capacity()) {
    write ("你已经喝太多了，再也灌不下一滴水了。\n");
    return 1;
  }

  can->add("液体/剩",-1);
  
  // 可以在容器上头设定饮用讯息 by ACKY
  if( !can->query("液体/饮用讯息") )
	message_vision ("$N把嘴巴对着" + can->name() + ", 咕噜噜地喝了几口" + can->query("液体/名称") + "。\n",me);

  if (!intp(can->query("液体/止渴")))
    me->add("water",10);
  else
    me->add("water",can->query("液体/止渴"));

  if ((int)me->query("water") > me->max_water_capacity())
    me->set("water",me->max_water_capacity());
  if (me->is_fighting()) me->start_busy(2);
  if (!can->query ("液体/剩")) {
    write ("你已经将" + can->name() + "里的" + can->query("液体/名称") +
           "喝得一滴也不剩了。\n");
    return 1;
  }

  if (can->query("get_poison"))
  {
    write ("糟了 ! 水里有毒 !\n");
    me->apply_condition (can->query("get_poison"),can->query("poison_power"));
  }

  switch(can->query("液体/种类")) {
    case "酒":
      me->apply_condition("drunk",
        (int)me->query_condition("drunk")
        + can->query("液体/酒精成份"));
      break;
  }

  return 1;
}
 
int help(object me)
{
	write(@HELP
指令格式 : drink <容器名称>
 
使用说明 :
	本命令可以用来喝溶液，如喝水，喝酒等等。
	当然，附近要有溶液可以喝才行，譬如水缸或者酒袋等等。
	喝了液体之后可以止渴，但是也有可能喝到毒药，不过喝
	到补药也不无可能。此外，喝酒不能喝太多，会伤身喔！
HELP
    );
    return 1;
}
