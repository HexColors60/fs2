//open/prayer/room/tanchun/26.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","练武场");
        set("long",@LONG

	天权门的练武场, 练武场上的弟子正在练掌法. 看看地上的掌
	印, 虽然先天乾坤功的威力无俦!!不过在初学者的手上使将起
	来却还是缺少那么一点霸气!!

LONG);

        set("outdoors", "/open/prayer");
        set("exits", ([ /* sizeof() == 4 */
        "north":__DIR__"20",		//练武场
	"south":__DIR__"2-door",	//练武场
	"west":__DIR__"27",		//练武场
	"east":__DIR__"25",		//练武场
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee2" : 1,		//弟子
  "/open/prayer/npc/trainee1" : 1,		//弟子
   		
]));
     
        set("light_up", 1);
        create_door("south","圣火刻纹精钢大门", "north",DOOR_CLOSED);
  setup();
}
