//open/prayer/room/youkoun/27.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","刑房");
        set("long",@LONG

        原来这里就是瑶光门私设的刑房!!在西域民间的传闻竟然
        是真的!!瑶光门主痛恨男人, 所以残杀男性为乐??这里的
        刑具都很奇怪, 还有好多是你从未见过的用具有!!天呀!!
        身为男性的人还不赶快跑出去??

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "south":__DIR__"2",     
        "north":__DIR__"26",    
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/chamber" : 2,         //弟子
                
]));
                
  setup();
}
