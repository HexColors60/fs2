//open/prayer/room/kitchen7

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "厨房");
  set ("long", @LONG

	    在旁边有着堆积如山的菜，及各式各样的
	肉类，和许多正要处理的食物，光看到这些菜
	量，就可以知道圣火教是一个非常庞大的组织
	了．

LONG);
  set("exits", ([ /* sizeof() ==  2*/
	"south" : "/open/prayer/room/kicthen4",		//`厨房
	"west" : "/open/prayer/room/kicthen6",		//`厨房
]));
   set("light_up", 1);

  setup();
}
