//open/prayer/room/youkoun/29.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","牢房");
        set("long",@LONG

        里面有一位男子, 身形虽然高大, 可是被困于此
	长年累月下来也会变得驼背了!!手上套着铁链,
	再加上全身伤痕累累, 行动颇为不便!!
		
LONG);

        set("exits", ([ /* sizeof() == 1 */
        "up":__DIR__"26",    
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/youkoun-man" : 1,           //燕十一
        ]));
                
  setup();
}

