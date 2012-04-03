//open/prayer/room/1-door

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "总坛玄关");
  set ("long", @LONG

    你现在所在的位置，正是圣火教主的房间，这是教主与教主夫人休息
    这是一条窄长的走道，再往北走就会到达，震惊中原武林的～圣火教
总坛了，在这条走廊的尽头传来一阵光亮的火光，莫非圣火教真的名如其
实，燃着不灭的圣火！！ 

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/major-officer" : 1,		
]));
  set("exits", ([ /* sizeof() == 2 */
	"enter" : "/open/prayer/room/punch1-13",		//`大厅
	"south" : "/open/prayer/room/train1",		//`练武场
]));

  setup();
}
 
