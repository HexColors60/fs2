//open/prayer/room/westarea/road14.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八达, 处处繁华. 往东北方可
	以到达圣火教的总坛. 西方则可以到达"天璇门"与"天机门"
	. 西域圣火教的位置刚好是在一个盆地之间, 地势由东向西
	下降, 南边则是盆地的开口!
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"road13",		//街道
        "west":__DIR__"road15",		//街道
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() ==  1*/
	"/open/prayer/npc/man1" : 1,		
        ]) );

    setup();
}
