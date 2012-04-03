//open/prayer/room/3elder6

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "戒律长老房");
  set ("long", @LONG

	    你己来到了戒律大厅了，往南走正是戒律
	长老的办公室，而北边及西边都有圣火弟子在
	练武的声音，看来戒律长老的功夫应该不错．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee4" :1 ,		//弟子
]));
  set("exits", ([ /* sizeof() ==  4*/
	"out" : "/open/prayer/room/train1-15",		//`走廊
	"north" : "/open/prayer/room/3elder5",		//`长老房
	"south" : "/open/prayer/room/3elder7",		//`长老房
	"east" : "/open/prayer/room/3elder3",		//`长老房
]));
  set("light_up", 1);

  setup();
}
 
