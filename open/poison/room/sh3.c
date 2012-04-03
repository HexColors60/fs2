// Room: /u/r/ranko/room/sh3.c
inherit ROOM;

void create ()
{
  set ("short", "茶店");
  set ("long", @LONG
一间供人饮茶休憩的小店，内里摆了几张桌子供人饮茶聊天，
不少村民常在工作完毕后来这里喝杯茶，小憩一番。店里除了卖各
种茶品之外，亦备有一些小菜供人取用。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"v2-4.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/mer3.c" : 1,
]));
  set("light_up", 1);

  setup();
}
