//open/prayer/room/tangi/tangi1-13.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","议事厅");
        set("long",
"在厅上可以见到许多较高职位的门徒，一个个面目严肃站在那里，等候着向门主报告
份内的职责，以便能让门主适时的处理掉棘手的问题．教头可能是没有什么问题吧！
看他一付很轻松的样子．\n");
        set("exits", ([ /* sizeof() == 2 */
        "south":"/open/prayer/room/tangi/tangi1-16",		//议事厅
        "west":"/open/prayer/room/tangi/tangi1-12",		//议事厅
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/general" : 1,		//教头
]));

   setup();
}
