//open/prayer/room/garden16.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花园");
        set("long",@LONG

	  行走到这里，眼前似乎有片烟雾四处扩散，
	不知哪来那么多烟雾，五尺内景像皆看的蒙胧
	不切........... 

LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 4 */
        "north":"/open/prayer/room/garden20",		//花园
        "south":"/open/prayer/room/garden12",		//花园
        "east":"/open/prayer/room/garden15",		// "
        "west":"/open/prayer/room/garden17",		// "
        ]) );
   setup();
}
