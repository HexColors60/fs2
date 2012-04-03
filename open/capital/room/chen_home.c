// Room: /open/capital/room/r69.c
#include "../../open.h"
#include <ansi.h>
inherit ROOM;

void create ()
{
    set("short",HIC"大理寺"NOR);
  set ("long", @LONG
这里就是全国最高的司法机构「大理寺”，这里专门处里一些重大案件
，以及审理所有隶属于大理寺的各司法部门，在这里不管是王公贵族，还是
朝廷重臣，只要犯了罪，都会秉公处理，绝不会循私。
 
LONG);

  set("exits", ([ /* sizeof() == 1 */
   "south":"/open/capital/room/r15",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/daemon/class/officer/master_chen":1,
   "/open/capital/npc/catcher":2,
]));
  set("valid_startroom",1);
/*
  set("no_fight", 1);


  set("no_magic", 1);
*/
  set("light_up", 1);
  setup();
  call_other("/obj/board/chen_b.c","???");
}
