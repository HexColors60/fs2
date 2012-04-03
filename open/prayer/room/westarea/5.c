//open/prayer/room/westarea/5.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","攀霞岭");
        set("long",@LONG

	曼丽山上的一座小山岭, 眼前所见是一些简朴的茅
	屋, 还有些牲畜在四处乱飞乱跑!!霞云满布, 好一
	股世外桃源之气息!!眼前这位便是圣火教副教主的
	结拜义兄了!!哇, 果真有缘相见, 是不是该向他道
	谢相救之恩呢??

LONG);
        set("exits", ([ /* sizeof() == 1 */
        "south":__DIR__"2",	
 
        ]) );
        set("light_up", 1);
        set("no_transmit",1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/high-man" : 1,		
        ]));
  setup();
}
