//open/prayer/room/horse5

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "马房");
  set ("long", @LONG

	    你来到一间恶臭不勘的房间，房间中没有
	任何一匹马匹，眼前所见的都是马匹的排泄物
	看来须要好好整理了．

LONG);

  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() ==  2*/
	"south" : "/open/prayer/room/horse6",		//`马房
	"east" : "/open/prayer/room/horse2",		//`马房
]));
setup();
}
 
