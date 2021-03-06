// Room: /open/capital/room/r72.c

inherit ROOM;

void create ()
{
  set ("short", "中央大街");
  set ("long", @LONG
走在京城的中央大街, 街上不时有快马奔过, 显示出这条街交通的
繁忙。路的西边是军机处, 归兵部尚书管理。路的东边是京城直设的民
政司, 专门负责平民的结婚事宜, 若你想与你的另一半共结连理的话,
请到民政司登记结婚吧。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"r34",
  "north" : __DIR__"r71",
  "west" : __DIR__"soldier_room",
  "east" : __DIR__"merry",
]));
  set("outdoors", "/open/capital");

  setup();
}
