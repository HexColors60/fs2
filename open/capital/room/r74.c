// Room: /open/capital/room/r74.c

inherit ROOM;

void create ()
{
  set ("short", "中央大街");
  set ("long", @LONG
这儿是皇城祭坛旁的街道, 因此装修的非常美观, 看起来一尘不染
的。由这儿可以通向云洋大街与环宫大道, 是到皇宫的必经之路。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r59",
  "north" : __DIR__"r08",
]));
  set("outdoors", "/open/capital");

  setup();
}
