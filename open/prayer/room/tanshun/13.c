//open/prayer/room/tanshun/13.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副门主房");
        set("long",@LONG

        副门主不待在书房, 竟跑到这里来了! 原来是有一件极机
        密的文件要私底下交待一位弟子去送! 看他们交头接耳的
        样子, 还真有那么一点点机密的味道!

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"12",            //副门主室
        "northeast":__DIR__"10",                
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
   "/open/prayer/npc/vice-chair" : 1,           
   "/open/prayer/npc/trainee3" : 1,             //弟子
                
]));
     
  setup();
}
