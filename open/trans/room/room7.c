#include <ansi.h>
inherit TRANS_ROOM;
void create()
{
    set("short","长沙城驿站");
    set("long",@LONG
这里是长沙城的驿站, 这里四处的可以看到, 家家门口都挂着一副弓
箭, 原来这里就是射手派的所在地。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/marksman/room/room1-13",
]));

    setup();
}

