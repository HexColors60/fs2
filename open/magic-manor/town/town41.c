inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "平原小径");
        set ("long", @LONG
走了许久，总算走到一条较像样的路了，前方不远处似乎是有人
烟的样子，可以看见几间零星的房子座落在前方。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "east"	: __DIR__"town38",
        "west"	: __DIR__"town40",
	]));

        setup();
}
