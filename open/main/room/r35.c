// Room: /open/main/room/r35.c

inherit ROOM;

void create ()
{
	set("short","道路");
  set ("long", @LONG
道路在此贯穿了一片原始森林 , 不时有些小猴子会跑到路上
来 , 真逗趣 , 一条黄土小径往东接去 , 不知通往何处 , 道路
继续往南北延伸 .

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"f22",
  "west" : __DIR__"f18",
  "north" : __DIR__"r33",
  "east" : __DIR__"r36",
]));

  set("outdoors", "/open/main");

  setup();
}
