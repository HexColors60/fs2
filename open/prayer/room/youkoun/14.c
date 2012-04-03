//open/prayer/room/youkoun/14.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","总管的书房");
        set("long",@LONG

        在书房的南方, 有个保镳正在偷空休息, 毕竟日以继夜地
        看守书房还是很累人的! 因此在没有重大事情的时候, 难
        免要找机会补充一下精神.

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "northwest":__DIR__"15",                //总管房
        "north":__DIR__"13",            //总管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/paltoon1" : 1,                //保镳
                
]));
     
  setup();
}
