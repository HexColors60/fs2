// made by chun,copy and re-edit by ccat
#include <room.h>
#include "/open/open.h"

inherit "/std/room/shop";

void create ()
{
	set ("short", "小商行");
  set ("long", @LONG
  这里是昆仑山唯一的商行,在这你可以估价(value),
卖断(sell),交易买货(buy),并可以察看这里有什么
货品待售(list).
LONG);

  set("exits", ([ /* sizeof() == 1 */
	"south" : __DIR__"v2",
]));

  set("objects", ([ /* sizeof() == 1 */
	__DIR__"npc/keeper" : 1,
]));

  set("light_up", 1);

  setup();
}
