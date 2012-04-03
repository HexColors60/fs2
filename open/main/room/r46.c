// Room: /open/main/room/r46.c

inherit ROOM;

void create ()
{
  set ("short", "黄土小路");
  set ("long", @LONG
这是一条人烟稀少的小路，弯弯曲曲的往南走，谁也不知到
最后它会通往那里，只知到有一个传说中的关卡海山关，在遥远
的天的那一方. 道路往东或往北.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"f28",
  "west" : __DIR__"f26",
  "north" : __DIR__"r45",
  "east" : __DIR__"r47",
]));

  set("outdoors", "/open/main");

  setup();
}
