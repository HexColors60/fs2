// Room: /open/main/room/[2].c

inherit ROOM;

void create()
{
	set("short", "蜀中城郊");
	set( "build", 22 );
	set("long", "你看到你的北方有一座城，屋瓦比临，煞是热闹，那应该是蜀
州要城蜀中城了. 你可以到那里看看，也许有你想要的东西. 道路
在此呈南北走向.
");

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r4",
  "north" : "/open/gsword/room/su0",
]) );


  set("outdoors","/open/gsword");
  setup();
}
