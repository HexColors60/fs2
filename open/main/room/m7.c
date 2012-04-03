// Room: /open/main/room/m7.c

inherit ROOM;

void create ()
{
  set ("short", "丘陵");
  set ("long", @LONG
你走上了连绵的土丘,微微的风轻拂着你,这里甚么都没有,
有着只是茫茫的芦花和蓝天.

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : "/open/main/room/F12",
 "north" : __DIR__"M14",
  "west" : "/open/main/room/m6",
  "east" : "/open/main/room/r12",
]));

  set("outdoors", "/open/main");

  setup();
}
