#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山洞");
	set("long", @LONG
这里是峭壁里的山洞，虽然说是个山洞，不过还是顶干静的，在这
里你还可以听见清析的滴水声。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "south" : __DIR__"cave",
            "east"  : __DIR__"cave2",
]));
	setup();
}



