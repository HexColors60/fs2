#include <room.h>
#include "../../open.h"
inherit ROOM;

void create ()
{
  set("short","诸葛草芦");
  set ("long", @LONG
这里是神算先生诸葛卧龙的住处，只看见墙上悬挂
的都是一些有关于八卦、大极、星相、面相等等占卜一
类的东西，这也是为何诸葛卧龙会有「神算先生”的名
号的原因。

LONG);

  set("exits", ([ /* sizeof() == 3 */
	"west" : "/open/snow/room/room3",
]));

  set("objects",([
	"/open/snow/npc/dguger" : 1,
	]));
  set("light_up", 1);

  setup();
}
