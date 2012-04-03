// Room: /open/main/room/M14.c

inherit ROOM;

void create()
{
	set("short", "环山长廊");
	set("long", @LONG
这长廊不知道有多长多高，环绕着山而上，直
入云雾中。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"south" : __DIR__"v10",
	"westup" : __DIR__"r2",
]));
	set("outdoors", "1");

	setup();
}
