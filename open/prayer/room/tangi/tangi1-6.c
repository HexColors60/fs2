//open/prayer/room/tangi/tangi1-6.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","天机门地牢");
        set("long","此处是明教分部之一的天机门地牢的内部.西边是地牢的出口(open door). \n");
        set("exits", ([ /* sizeof() == 4 */
        "north":"/open/prayer/room/tangi/tangi1-5",		//石牢房
        "south":"/open/prayer/room/tangi/tangi1-7",		//石牢房
        "east":"/open/prayer/room/tangi/tangi1-9",		//地牢
        "west":"/open/prayer/room/tangi/tangi1-4",		//地牢门
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/picket" : 1,		//监狱巡察
]));
	create_door("west", "地牢铁门", "east", DOOR_CLOSED);
  setup();
}
