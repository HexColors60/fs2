inherit ROOM;
#include <way.c>

void create()
{
	set("short","蛇寨 地下室");
	set("long",@LONG

		～　正北方有亮光，不过依旧黑暗 ～

LONG);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/poison_soldier":3,
]));
	set("exits",([
"south":__DIR__"r-41",
"north":__DIR__"r-43",
]));
	setup();
}
