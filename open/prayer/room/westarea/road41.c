//open/prayer/room/westarea/road41.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八达, 处处繁华. 西边是通往飘渺四
	宫之末的"朱雀宫". 
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 1 */
        	"north":__DIR__"road39",		//街道

        ]) );
        set("no_fight", 0);
        
  setup();
}
