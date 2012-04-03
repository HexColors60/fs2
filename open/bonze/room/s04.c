// Room: /open/soulin/room/s04.c

inherit ROOM;

void create()
{
	set("short", "少林寺前广场");
	set("long", @LONG
	这里是少林弟子们练功的场所，四周摆满了练功的器具。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"s01",
  "east" : __DIR__"s05",
]));
        set("objects", ([ /* sizeof() == 1 */
    "/open/bonze/npc/s_monk":2,
]));
  set("outdoors", "/open/bonze");

	setup();
}
