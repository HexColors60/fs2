// Room: /open/ping/room/p5
#include </open/open.h>
inherit ROOM;

void create ()
{
  set ("short", "休息室");
  set ("long", @LONG
这儿是段王爷特别拨出来的一间房间, 作为段家子弟休息的房间, 
因此除了段家的人以外, 别的人是进不来的。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"p2",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/duan3" : 1,
]));
  set("no_magic", 1);

  setup();
}
