inherit ROOM;
#include <ansi.h>

void create()
{
        set("short",HIG"琰 扬 居 -- 后 院"NOR);
	set("long",@LONG
屋内的装潢十分的朴素，除了一张大黄石桌与一些木椅以外，就
没有其他的摆设了。
LONG);
        set("evil_area",1);
        set("no_transmit",1);
	set("exits",([
"out":__DIR__"b-26",
]));
	setup();
}
