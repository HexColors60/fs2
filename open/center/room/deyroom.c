// Room: /u/l/lotus/girl/deyroom.c

#include "/open/open.h"
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "彩蝶姑娘的房间");
  set ("long", @LONG
彩蝶姑娘必定是个极爱花的人, 因为房中各处都以鲜花点缀着,
散发着浓郁的花香, 连大床上都洒满了花瓣, 躺在上面一定像跌进了
花堆里那么舒服, 彩蝶姑娘正快乐的跳着舞.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : CENTER_ROOM"f2c",
]));
  set("objects", ([ /* sizeof() == 1 */
  CENTER_NPC"dey.c" : 1,
]));
  set("light_up", 1);
  set("file_name", CENTER_ROOM"deyroom.c");
  create_door("west", "雕花木门", "east", DOOR_CLOSED);
  setup();
}
