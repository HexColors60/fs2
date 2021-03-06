// Room: /open/main/room/r4.c

inherit ROOM;

void create()
{
	set("short", "蜀中隘口");
	set( "build", 10 );
	set("long", "道路到此突然急剧的狭碍，两旁的山壁直迫路前，在此形成
一到隘口，拥有一夫当关，万夫莫敌的气势，蜀中城靠此天险，
不知渡过多少大风大浪. 道路在此呈南北走向.
");

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"[2]",
  "south" : __DIR__"r6",
]) );

  set("outdoors", "/open/main" );

  setup();
}
