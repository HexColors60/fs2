// Room: /open/dancer/room/r5-2.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","山丘");
  set ("long", @LONG
你身处在山丘之上，在你的东边是一条小路，北方是草原而南方则
可远远看到村庄，西方数里外则是海洋了。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/dancer/room/r5-3.c",

]));

  set("light_up", 1);

  setup();
}
