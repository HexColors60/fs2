// Room: /open/center/room/tin4.c
#include "/open/open.h"

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "楼梯口");
  set ("long", @LONG
和彩厅迥然不同的气氛, 两张雕花椅, 一幅山水的泼墨画, 几枝
寒梅, 安静的绽放着傲然的气质. 有一道楼梯通往二楼小姐的房间,
南面有一扇雕花木门.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"tin3.c",
  "south" : __DIR__"r10.c",
  "up" : __DIR__"f2a.c",
//  "east" : __DIR__"gstore",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/center/npc/chang.c" : 1,
]));
  create_door("south", "雕花木门", "north", DOOR_CLOSED);
  setup();
}
