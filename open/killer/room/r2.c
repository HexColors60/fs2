#include <room.h>
#include "../../open.h"
inherit ROOM;

void create ()
{
  set("short","洞穴入口");
  set ("long", @LONG
这个洞穴看起来挺神秘似的，洞穴的石壁刻着一条龙的形状
相传武林中有一个杀手组织，名叫「黑牙联”，据闻此组织十分
神秘，所培养出来的杀手，杀无不克，夺人命于瞬间，而这个组
织的象征标制，和这条龙形十分类似。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
	"out":__DIR__"r1",
	"enter":__DIR__"r3",
]));
       set("objects",([
   "/open/killer/npc/guard.c" : 2,  ]));

  setup();
}
