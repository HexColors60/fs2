// Room: /open/capital/room/r05.c

inherit ROOM;

void create ()
{
  set ("short", "环宫大道");
  set ("long", @LONG
你现在来到京城内的大街, 高耸的围墙和华丽的基石, 北方的城楼
烘托出一股庄严肃穆的气氛, 皇上所住的皇宫便位于北方, 而整齐宽敞
的街道更显出北方皇宫的气派。

LONG);

  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"convert_room.c",
  "west" : __DIR__"r04",
  "east" : __DIR__"r07",
]));
  set("gopath", "east");

  setup();
}
