//u/r/rence/room/kitchen5

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "厨房");
  set ("long", @LONG

圣火教总坛的厨房. 

LONG);
  set("outdoors", "/u/r/rence/room");
  set("exits", ([ /* sizeof() ==  2*/
	"south" : "/u/r/rence/room/kicthen2",		//`厨房
	"east" : "/u/r/rence/room/kitchen6",		//`厨房
]));

  setup();
}
 
