//open/prayer/room/train1-6

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "练武场");
  set ("long", @LONG

	    在圣火教总坛的练武场，你看到许多圣火
	弟子拼命的勤练武功．看来圣火教的入主中原
	野心不小． 

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee1" : 3,
]));
  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() == 2 */
	"south" : "/open/prayer/room/train1-11",		//练武场
	"west" : "/open/prayer/room/train1-7",		//`练武场
]));

  setup();
}
 
