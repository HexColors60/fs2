//open/prayer/room/kiyan/13.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","练武场");
        set("long",@LONG

	开阳门的练武场, 练武场上的弟子正在训练腿力. 传闻圣火教的武
	学共有三套, 第三便是乾坤大挪移的步法, 是教主由东土所习得的
	武学!!能够巧妙的避开敌人的攻击!!

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 3 */
        "east":__DIR__"11",		//走廊
	"south":__DIR__"20",		//练武场
	"west":__DIR__"14",		//练武场
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee2" : 1,		//弟子
  "/open/prayer/npc/trainee4" : 1,		//弟子
   		
]));
     
  setup();
}

 int valid_leave(object me, string dir)
  {
    if(dir=="east"&&me->query("gender")=="女性")
        return notify_fail("女人是无法进入副门主的办公房的 !\n");
        
   return 1;
}
