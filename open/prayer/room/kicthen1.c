//open/prayer/room/kicthen1

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "厨房");
  set ("long", @LONG

	    你面前正有一个人忙的满头大汗，因为他
	要供应圣火教，门主以上的伙食，万一有所差
	错，难保有性命之忧．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/cooker" : 1,		//厨师
]));
  set("exits", ([ /* sizeof() ==  1*/
	"north" : "/open/prayer/room/kicthen3",		//`厨房
]));
   set("light_up", 1);
  setup();
}
 
