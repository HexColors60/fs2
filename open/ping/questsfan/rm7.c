// Room: /u/d/dhk/questsfan/rm7
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "山林"HIY"跂"NOR"路");
  set ("long", @LONG
你越爬越高，而四周的雾也越来越浓，这好像意味着周
围的危险性相对也越来越高。四周传来令人惊耸的响声。
 ───沙沙───   ─《吼》─   ───沙沙─── 

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"rm8.c",
  "eastdown" : __DIR__"rm6",
]));
  set("outdoors", "/u/d");

  setup();
}
