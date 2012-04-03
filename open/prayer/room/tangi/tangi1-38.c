//open/prayer/room/tangi/tangi1-38.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","厨房");
        set("long",
"天机门的厨房,厨师的工作就是负责填满全门上下所有门人的肚皮. 他正在悠闲地料
理着等会要开饭的菜色哩!!\n");

        set("exits", ([ /* sizeof() == 1 */
        "north":"/open/prayer/room/tangi/tangi1-36",		//厨房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/cooker" : 1,		//厨师
   		
]));
     
  setup();
}
