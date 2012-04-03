// Room: /open/main/room/r15.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set("long", "	这里北方是一片的森林，南方则是一望无际的草原，
	再往东方过去有座城门，应该就是王朝的中心－京城
	的出入口了。

");

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"s16",
  "west" : __DIR__"r14",
  "north" : __DIR__"f15",
   "east" : "/open/capital/room/D01",
]) );

  set("outdoors", "/open/main" );


  setup();
}
