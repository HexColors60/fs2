//open/prayer/room/train1-7

#include <ansi.h>
inherit ROOM;

void create ()
{
 set ("short", "总坛练武场");
  set ("long", @LONG

	    你看到圣火弟子，在圣火教总坛的练武场
	上，拼命的勤练武功．面前这个弟子还练得有
	模有样的．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee4" : 1,		//弟子
]));
  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() == 4 */
	"north" : "/open/prayer/room/train1",		//`练武场
	"south" : "/open/prayer/room/train1-12",		//`练武场
	"east" : "/open/prayer/room/train1-6",		//`练武场
	"west" : "/open/prayer/room/train1-8",		//`练武场
]));

  setup();
}
 
