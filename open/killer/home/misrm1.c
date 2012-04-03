#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set("short","装备室");
  set ("long", @LONG
这里是黑牙联出任务领取兵器的地方，在这里可以看到不少的兵器
你可以看到一个装备箱，只有叶秀杀同意才可以拿取。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "down":__DIR__"masterm.c",
  "east":__DIR__"misrm3.c",
]));

  set("objects",([
/*        "/open/killer/npc/spy1": 1, */
        "/open/killer/obj/misbox1.c": 1,
]));
  setup();
}
void init()
{ 
   add_action("do_search","search");
}
int do_search()
{
   object me;
   me = this_player();
   
   if (me->query_temp("god")==1)
   {
    tell_room(me,""+me->query("name")+"发现路，往北边走去。\n");
    me->set_temp("key",0);
    me->move(__DIR__"misrm2.c");
    return 1;
   }
   return 0;
}
