// Room: /u/m/moner/tree/room6.c
inherit ROOM;

void create ()
{
  set ("short", "薜荔萝林");
  set ("long", @LONG

一大片的薜荔萝林耸立在你眼前，阵阵的薜荔花香随风飘送，你的直
觉告诉你不要前进，可是又忍不住内心的好奇。
满天的彩霞笼罩着天际，一抹夕阳慢慢的消失在地平线。

LONG);

  set("light_up", 1);
  set("outdoors", "wind");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room7.c",
  "north" : __DIR__"room5.c",
]));

  setup();
}
