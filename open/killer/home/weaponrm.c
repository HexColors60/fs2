#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set("short","兵器室");
  set ("long", @LONG
这里是黑牙联平时储存兵器的地方，在这里可以看到不少的兵器
但是大多是暗器，只有黑牙联的弟子可以在这里领取兵器，但是必须
先向掌理兵器的兵器使报备(report)，想知道有什么兵器就用(list)。
这里也是存放旧玩家留下的装备的好地方。多多照顾新人吧！
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "up":__DIR__"ru2.c",
]));

  set("objects",([
        "/open/killer/npc/manager": 1,
        "/open/killer/npc/young": 1,
]));
  setup();
}
void init()
{ 
   add_action("do_open","open");
}
int do_open()
{
   object me;
   me = this_player();
   
   if (me->query_temp("key")==3)
   {
    tell_room(me,""+me->query("name")+"打开门，往专用兵器室走去。\n");
    me->set_temp("key",0);
    me->move(__DIR__"haterm.c");
    return 1;
   }
   return 0;
}
