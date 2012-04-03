//__DIR__"19.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","总管的书房");
        set("long",@LONG

	玉衡门总管的书房, 这里是总管处理门务的地方. 你
        看到总管刚将文件放下准备起身. 大概是己处理完所
        有的文件准备去休息室休息了吧. 

LONG);

        set("exits", ([ /* sizeof() == 3 */
        "northeast":__DIR__"16",		//总管房
        "southeast":__DIR__"18",		//总管房
        "east":__DIR__"17",		//总管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/general-manager" : 1,		//总管
   		
]));
     
  setup();
}
