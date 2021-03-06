// Room: /open/main/room/M14.c

inherit ROOM;

void create()
{
	set("short", "昆仑山顶");
	set("long", @LONG
你来到这儿，视野忽地广阔开来。一眼望去
不再是奇石峋嶙的山道，却是一个偌大的银色山
谷，白雪皑皑，到处长满了平地难得一见的花草
山谷之中还有一个天池，虽是平静无波，但却也
不冻不冰，十分奇特。

LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"south" : __DIR__"r4",
	"east" : __DIR__"m2",
	"west" : __DIR__"m8",
	"north" : __DIR__"m6",
]));
	set("outdoors", "1");

	setup();
}
