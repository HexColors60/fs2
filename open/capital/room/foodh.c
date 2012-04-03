// Room: /open/capital/npc/foodh
inherit ROOM;

void create ()
{
  set ("short", "粮仓");
  set ("long", @LONG
一进门，发现眼前堆满了一袋袋用麻布做成的米袋，排列整齐，好
像小山一样高。辛苦的士兵赤裸着上身听着长官的指示整理着这些重要
的米粮。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/capital/room/farm",
]));


  set("light_up", 1);
  set("objects",([
  "/open/capital/npc/managerwu":1,
  ]));

  setup();
}
