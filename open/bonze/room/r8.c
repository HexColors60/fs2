// Room: /open/soulin/room/r8.c

inherit ROOM;

void create()
{
	set("short", "候客亭");
	set("long", @LONG
	由于寺内有诸多的限制，例如女流不得进入寺中
	等，故造此候客亭让来访寻人的施主们有个休息
	等候的地方。
	往北过了寺门就进入了少林寺。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r2",
  "north" : __DIR__"D01",
]));
	set("light_up", "1");

	setup();
}
