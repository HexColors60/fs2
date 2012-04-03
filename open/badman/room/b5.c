// Room: /open/badman/room/b5
inherit ROOM;

void create ()
{
  set ("short", "殿前大道");
  set ("long", @LONG
你来到了恶人谷的殿前大道，聚集的人也渐渐多了起来，你不
时可以看到北边的房间有人进进出出，个个獐头鼠目，看来都不是
什么好东西，不愧是强盗窝的中心。
    你听到南边传来阵阵的吆喝声，十分吓人。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"b6",
  "south" : __DIR__"r6",
  "north" : __DIR__"r7",
  "east" : __DIR__"b4",
]));
  set("outdoors", "/open/badman");

  setup();
}
