///open/prayer/room/hole/3.c

inherit ROOM;

void create()
{
	set("short", "洞穴");
	set("long", @LONG

	眼前似乎有片烟雾四处扩散，不知哪来那么多烟雾，五尺内景像皆
	看的蒙胧不切，只见墙上模模糊糊的刻有几个字"危险!莫入!"霎那
	间周围杀气迅速膨胀，是生是死，一切只有各安天命!!

LONG	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"4",
  "south":__DIR__"5",
  "west":__DIR__"2",
]));
        set("evil",1);
        set("no_auc",1);
        set("no_transmit",1);
	setup();
}