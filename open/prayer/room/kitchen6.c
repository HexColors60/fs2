//u/r/rence/room/kitchen6

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "厨房");
  set ("long", @LONG

圣火教总坛的厨房. 

LONG);
  set("outdoors", "/u/r/rence/room");
  set("exits", ([ /* sizeof() ==  4*/
	"out" : "/u/r/rence/room/train1-19",		//`走廊
	"east" : "/u/r/rence/room/kitchen7",		//`厨房
	"south" : "/u/r/rence/room/kicthen2",		//`厨房
	"west" : "/u/r/rence/room/kitchen5",		//`厨房
]));

  setup();
}
 
