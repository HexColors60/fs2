inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIG"琰 扬 居 -- 后 院"NOR);
	set("long",@LONG
你正走在砖瓦铺地的道路上，两旁各式一个马厩与大榕树，往南
有一间木制的房屋，隐隐约约中，你可以听到一些哀怨的哭泣声，仿
佛是从木屋内传出来的，往北则通往大厅内。
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"north":__DIR__"b-18",
"south":__DIR__"b-24",
"east":__DIR__"b-22",
"west":__DIR__"b-20",
]));
	setup();
}

 