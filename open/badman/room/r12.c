// Room: /open/badman/room/r12
inherit ROOM;

void create ()
{
  set ("short", "武道馆内厅");
  set ("long", @LONG
来到这里，你马上感到一股严肃的气氛，外面大厅的吵杂声似
乎也完全被掩盖了过去。四面的墙上装饰着各式各样的奇珍异宝，
但是都抵不过你正前方的墙上所挂着的大狮头来的引人注目。你看
到房间的中央放了一张狮皮装饰的大椅。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"r6",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/badman/npc/te" : 1,
]));
  set("light_up", 1);

  setup();
}
