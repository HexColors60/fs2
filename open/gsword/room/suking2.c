// Room: /u/s/smore/room/suking/suking2.c

inherit ROOM;

void create ()
{
  set ("short", "府衙大厅");
  set ("long", @LONG
走进这大厅，周围肃穆的气氛让你不敢四处乱看，不过你依
然可以感觉得到四周的装设气派堂皇，又不流于俗套可见大将军
左正也不是一个只会打战的草包.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : "/open/gsword/room/suking3",
  "north" : "/open/gsword/room/suking7",
  "east" : "/open/gsword/room/suking9",
]));

  set("light_up", 1);

  setup();
}
