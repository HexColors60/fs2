//open/prayer/room/westarea/road2.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八达, 处处繁华. 北边的小山
	丘是总坛的所在地, 红瓦层层, 在阳光的照耀下, 看起来就
	像是一座红色的火山........
LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"road4",		//街道
        "west":__DIR__"road1",		//街道
 
        ]) );
        
        set("no_fight", 0);
        
  setup();
}
