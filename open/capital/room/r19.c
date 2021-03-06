// Room: /open/capital/room/r19.c

inherit ROOM;

void create ()
{
  set ("short", "三叉路口");
  set ("long", @LONG
往北走可通往三大城门之一的威西门，不过你得通过严密的重重检
查才可通关。东边的街道便是所谓的云洋大街, 唯有一些权大势大的人
物才住的起这条街。
    由于这里邻近皇城，附近又多是达官贵人们的住所，所以禁卫军的
巡逻也特别严密，别想在这儿闹事，那对你绝对没好处。

LONG);

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"r20",
  "north" : __DIR__"r18",
  "east" : __DIR__"r54",
]));

  set("gopath", "north");

  setup();
}
