#include "/open/open.h"

inherit ITEM;

void create()
{
        set_name("纸包", ({ "paper" }) );
        set("unit", "包");
        set("long", "一包纸包，似乎可以打开看看。\n");
        set("no_sell", 1);
	setup();
}

void init()
{
  add_action("do_open", "open");
}

int do_open (string arg)
{
  object	me=this_player();
  int		query;

  if (!arg || arg != "paper")
	return 0;
  
  query = me->query_temp("quests/badman_license");

  message_vision("$N把手中的纸打开。\n", me);
  if (query >= 3) {
    me->set_temp("quests/badman_license", 4);
    tell_object(me, "你发现纸里面包着一堆药粉，也许是蒙汉药吧。\n");

    new(MAIN_OBJ"drug")->move(me);
    destruct (this_object());
  }
  else set ("name", "打开的纸包");
  return 1;
}
