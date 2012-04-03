// Room: /open/badman/room/b4
inherit ROOM;

void create ()
{
  set ("short", "十字路口");
  set ("long", @LONG
你走到了一个十字路口，两条街道各自往南北两方延伸下去。
往西可直接通往恶人谷主的大殿，不过一路上似乎戒备森严的样子
，还是别乱闯的好。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"b5",
  "north" : __DIR__"b8",
  "south" : __DIR__"b14",
  "east" : __DIR__"b3",
]));
  set("outdoors", "/open/badman");

  setup();
}
