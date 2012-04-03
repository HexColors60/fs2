// Room: /open/badman/room/b3
inherit ROOM;

void create ()
{
  set ("short", "恶人谷大街");
  set ("long", @LONG
道路逐渐开阔，两旁的房子也渐渐多了起来，这恶人谷虽然是
与世隔绝，但看来谷中还是应有尽有，与外面的世界看起来没什么
差别。唯一令你感到不同的地方，或许是那种无时无刻不存在的压
迫感吧。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"b4",
  "east" : __DIR__"b2",
]));
  set("outdoors", "/open/badman");

  setup();
}
