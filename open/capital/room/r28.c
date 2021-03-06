// Room: /open/capital/room/r28.c

inherit ROOM;

void create ()
{
  set ("short", "永安胡同");
  set ("long", @LONG
城南的小巷。和市中心的热闹相比，这儿显得冷清多了，南边就是
高耸坚固的城墙，可以看到士兵在城墙上来回巡逻着。往西北去即是日
落驰道。
    这里有禁卫军四处的巡逻着，所以你还是不要在城内惹事的好。

LONG);

  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"r30",
  "northwest" : __DIR__"r27",
]));
  set("gopath", "northwest");
  set("gopath2", "east");

  setup();
}
