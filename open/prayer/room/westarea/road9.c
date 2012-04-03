//open/prayer/room/westarea/road9.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八达, 处处繁华, 西边是西域著名
	的市集, 你可以在那里买卖物品!!或许你可以在那里买到特殊的
	武器喔!!不过那可要看你的运气如何了........
    东边, 就是西域的驿站了
LONG);

       	set("outdoors", "/u/r/rence");
       	set("no_fight", 0);
	set("exits", ([ /* sizeof() == 3 */
       	"north":__DIR__"road1",		//街道
	"south":__DIR__"road13",	//街道
	"west":__DIR__"sushop",		//商店
    "east" : "/open/trans/room/room6", //驿站
 
        ]) );
        setup();
}
