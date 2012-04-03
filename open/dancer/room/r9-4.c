// Room: /open/dancer/room/r9-4.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","小路");
  set ("long", @LONG
你正走在山野小路之中，这里离村庄较远了，你的南方是一大片的
草原，远方则是一片森林。
。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/dancer/room/r10-4.c",
  "west" : "/open/dancer/room/r9-3.c",

]));

  set("light_up", 1);

  setup();
}
