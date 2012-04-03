// Room: /open/main/room/r25.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set("long", "你正走在一条山谷中, 也因此这儿车马相接, 络绎不绝, 最吸
引人的是, 这附近的山区常常有特种药草出现, 因此采药草的武林
人士不远千里而来. 道路在此呈东西走向.
");

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"M12",
  "west" : __DIR__"r24",
  "south" : __DIR__"m17",
  "east" : __DIR__"r26",
]) );

  set("outdoors", "/open/main" );


  setup();
}
