//open/prayer/room/train1-14

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG

	    再往南走就是戒律房了，北方是传功房及
	通往圣火教的各部门的路，面前有一个值班弟
	子正在巡查．

LONG);
  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/duty" : 1,		
]));
  set("exits", ([ /* sizeof() == 2 */
	"south" : "/open/prayer/room/train1-19",		//`走廊
	"north" : "/open/prayer/room/train1-9",		//`走廊
]));

  setup();
}
 
