// made by chun,copy and re-edit by ccat
#include <room.h>
#include "/open/open.h"

inherit "/std/room/shop";

void create ()
{
	set("short","史家商店");
  set ("long", @LONG
这里是枫林港最大的商店 . 物品的数量之多 , 种类之丰 , 
在全国都是首屈一指的 . 这家店的老板是本地的大盐商史怀恩 ,
 现在由他的三儿子史贵负责打理 . 你可以看看这里有些甚么(list)
交易(buy) , 还有估价(value) .
也可以看看这里有卖那些种类的东西(view)
LONG);

  set("exits", ([ /* sizeof() == 1 */
	"east" : "/open/port/room/r1-4",
]));
  set("light_up", 1);

  setup();
}
