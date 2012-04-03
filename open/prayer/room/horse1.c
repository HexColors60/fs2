//open/prayer/room/horse1

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "马房");
  set ("long", @LONG

　　　　    这是教主坐骑专用的马房，派有专人的看
	管，因此这间马房比其它马房干净多了，而且
	面前的神驹，正是日行千里的爪黄飞电．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/horse-looker" : 1,		//马夫
]));
  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() ==  1*/
	"west" : "/open/prayer/room/horse3",		//`马房
]));

  setup();
}
 
