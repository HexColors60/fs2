//open/prayer/room/westarea/road36.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八达, 处处繁华. 往东可以到达圣
	火教支门的"阵势门". 阵势门的规模虽然不会比天机门大, 可是
	势力却与天机门相去不远, 原因是因为此门的门主是文星君的得
	意弟子!!北边则是当铺.
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"suhock",	//当铺
        "east":__DIR__"road35",		//街道
        "west":__DIR__"road37",		//街道
 
        ]) );
        
        set("no_fight", 0);
        
  setup();
}
