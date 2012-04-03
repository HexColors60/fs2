// Room: /open/capital/room/r03.c

inherit ROOM;

void create ()
{
  set ("short", "环宫大道");
  set ("long", @LONG
走到这儿, 越来越能感受到皇朝严肃的气氛与豪华, 仔细一看路上
的石板, 竟然也雕了复杂的图案, 两旁建筑高耸, 仰望之下不禁升起敬
畏的心情。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/capital/room/r02",
  "east" : "/open/capital/room/r04",
]));

  set("gopath", "east");

  setup();
}
