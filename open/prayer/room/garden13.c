//open/prayer/room/garden13.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花园");
        set("long",@LONG

血红色的浓雾飘来,闻起来有股腥味!!令人的意识渐渐模糊....... 

LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
        "north":"/open/prayer/room/garden17",		//花园
        "south":"/open/prayer/room/garden9",			// "
        "east":"/open/prayer/room/garden12",			// "
        ]) );
   setup();
}
