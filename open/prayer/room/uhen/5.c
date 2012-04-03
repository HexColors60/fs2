//open/prayer/room/uhen/5.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","玉衡门大厅");
        set("long",@LONG

        整座大厅上除了放些武器外. 墙上也挂着一些画, 画
        中的景物主要都是一些飞禽在天空飞翔的图画. 看来
        门主似乎对于这方面有特别的喜爱..
	厅上所站立的是玉衡门的左护法．

LONG);
        set("exits", ([ /* sizeof() == 3 */
        "south":__DIR__"8",		//大厅
        "east":__DIR__"4",	            	//门主
        "west":__DIR__"23",	             	//练功房
 
        ]) );
        set("no_fight", 1);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/left" : 1,		//左护法
]));
  setup();
}

int valid_leave(object me, string dir)
  {
  if(dir=="west" && me->query("class") != "prayer")
        return notify_fail("不是教徒是不能进入的 !\n");
        
	return ::valid_leave(me,dir);
}
