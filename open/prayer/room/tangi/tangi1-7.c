//open/prayer/room/tangi/tangi1-7.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","石牢");
        set("long",@LONG
此处是明教分部之一的天机门内部的石牢. 
LONG);
        set("exits", ([ /* sizeof() == 1 */
        "north":"/open/prayer/room/tangi/tangi1-6",		//地牢
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/picket" : 1,		//监狱巡察
]));

   setup();
}
