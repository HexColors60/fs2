//open/prayer/room/3elder4

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "戒律长老房");
  set ("long", @LONG

	    这里有一个小石桌，在石桌的四周，丛花
	盛开，鸟语花香，使人有一种想坐下来休息休
	息的想法．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee4" : 1,		//弟子
]));
  set("exits", ([ /* sizeof() ==  2*/
	"north" : "/open/prayer/room/3elder3",		//`长老房
	"west" : "/open/prayer/room/3elder7",		//`长老房
]));
  set("light_up", 1);

  setup();
}
 
