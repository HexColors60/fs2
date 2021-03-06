#include <ansi.h>
inherit F_CLEAN_UP;
 
int help();

int main(object me, string arg, int repeat)
{
  object  ob;
  int     max_food;
  int     i;

  seteuid(getuid(me));

  max_food = me->max_food_capacity();
  if (!arg)
    return help();
  if (!objectp(ob = present (arg, me)))
    return help();

  if (repeat <= 0) repeat = 1;

  for (i=0; i<repeat; i++) {
    if (stringp(ob->query ("食物/额外函数")))
      return call_other(ob, ob->query ("食物/额外函数"), me, arg);

    if (!ob->query ("食物/剩")) {
      write ( ob->name() + "已经没什么好吃的了。\n");
      return 1;
    }

    if ((int)me->query ("food") >= max_food) {
      write ("你已经吃太饱了，再也塞不下任何东西了。\n");
      return 1;
    }

    if( me->is_fighting() ) me->start_busy (2);
    ob->set ("value", 0);

    // This allows customization of drinking effect.
    if (ob->query ("get_poison"))
    {
      write ("糟了 ! 食物里有毒 !\n");
      me->apply_condition (ob->query("get_poison"),
              ob->query("poison_power"));
    }
    me->add ("food", ob->query ("食物/供应"));
    if (me->query ("food") >= max_food)
      me->set ("food", max_food);
    ob->add ("食物/剩", -1);
    if( !ob->query ("食物/剩") ) {
      message_vision("$N将剩下的" + ob->name() + "吃得干干净净。\n", me);
      if( !ob->finish_eat() )
        destruct(ob);
      return 1;
    }
    else
      message_vision("$N拿起" + ob->name() + "咬了几口。\n", me);
  }

  return 1;
}
 
int help()
{
        write(@HELP
指令格式 : eat <食物名称>
使用说明 :
        本指令可以用来吃东西, 例如吃鸡腿: eat leg
        注意, 别吃到有毒食物喔!
其他参考 :
        drink
HELP
    );
    return 1;
}
