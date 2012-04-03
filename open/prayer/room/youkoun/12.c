//open/prayer/room/youkoun/12.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","总管的书房");
        set("long",@LONG

        这里站着两个保镳, 从你进来时就一直不怀好意地看着你
        . 看到这个小书房竟然有这么多保镳, 你不禁为瑶光门的
        人事编制感到不以为然..

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "southwest":__DIR__"15",        //总管房
        "south":__DIR__"13",            //总管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/paltoon1" : 1,                //保镳
        "/open/prayer/npc/paltoon2" : 1,                //保镳
                
]));
     
  setup();
}
