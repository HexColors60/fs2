// Room: /open/capital/room/r58.c

inherit ROOM;

void create ()
{
  set ("short", "云洋大街");
  set ("long", @LONG
这里往北可以到达布政司，其专门管理城内柴米油盐酱醋茶以及房
屋租售的问题，若你想买个家, 或是想找地方创个帮派, 这里将会提供
你完整的资讯。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"M10",
  "west" : __DIR__"r56",
  "east" : __DIR__"r59",
]));
  set("shoyr", "云洋大街");
  set("outdoors", "/open/capital");

  setup();
}
