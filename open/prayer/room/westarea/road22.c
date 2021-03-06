//open/prayer/room/westarea/road22.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八达, 处处繁华. 西方可以到
	达"天璇门"与"玉衡门". 西边较小的山脉人称"曼丽山", 山
	林苍翠, 绿意盎然, 一点也不像是西域的领土之一. 
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"road21",		//街道
        "west":__DIR__"road23",		//街道
 
        ]) );
        set("objects",([ /* sizeof() ==  1*/
        "/open/prayer/npc/sister" : 1,		
        ]) );
        
        set("no_fight", 0);
    setup();
}
