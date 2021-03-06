// Room: /open/capital/room/h16.c

inherit ROOM;

void create ()
{
  set ("short", "萝卜胡同");
  set ("long", @LONG
	北面有座大屋，大门上贴着一副对联，上头写着：

	             奇珍异宝我照收；

  	             破铜烂铁亦不拒。

	门上的横联写着：「今日有人，典当请内洽。”

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/vendor" : 1,
]));
  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"h15",
  "north" : __DIR__"caphock",
  "east" : __DIR__"r44",
]));

  setup();
}
