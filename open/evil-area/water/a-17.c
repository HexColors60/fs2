inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC"琰 扬 湖"NOR);
	set("long",@LONG
在你的正北方的湖面上，漂浮着一座建筑物，你不断的观看着建
筑物本身，可惜由于你身处于建筑物背面不远的南边岸上，所以根本
无法看的到内部是长的如何，南边传来阵阵孩童的喧哗声～打乱了你
的思绪...
LONG);
	set("objects",([
__DIR__"npc/mob02":3,
]));
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"west":__DIR__"a-18",
"east":__DIR__"a-16",
"south":__DIR__"a-30",
]));
	setup();
}

 