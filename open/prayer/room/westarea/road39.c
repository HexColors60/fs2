//open/prayer/room/westarea/road39.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八达, 处处繁华. 北边是往瑶光门,
	南边是往朱雀宫. 飘渺城是西域的一另一个教派, 虽然说分布的范
	围较分散, 可是其隐藏的实力到现在仍是一个未知的变数.
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"road34",	//街道
	"south":__DIR__"road41",	//街道
	"east":__DIR__"road38",		//街道
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() ==  1*/
	"/open/prayer/npc/woman3" : 1,		
        ]) );

  setup();
}
