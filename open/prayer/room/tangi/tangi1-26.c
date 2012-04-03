//open/prayer/room/tangi/tangi1-26.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","练武场");
        set("long",
"练武场上的弟子一个个都在磨练自己的体能，只希望能够早一天具备修习先天干
坤功的资格!!\n");

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 4 */
        "north":"/open/prayer/room/tangi/tangi1-21",		//练武场
	"south":"/open/prayer/room/tangi/tangi1-31",		//练武场
	"east":"/open/prayer/room/tangi/tangi1-27",		//练武场
        "west":"/open/prayer/room/tangi/tangi1-25",		//练武场
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee2" : 1,		//弟子
  "/open/prayer/npc/trainee4" : 1,		//弟子
   		
]));
     
  setup();
}
