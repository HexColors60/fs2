// Room: /u/l/lotus/f2a.c
inherit ROOM;

void create ()
{
  set ("short", "楼梯口");
  set ("long", @LONG
二楼是小姐们的房间的所在, 东面有一扇大窗, 你可以看到外面
的景色.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"f2b.c",
  "down" : __DIR__"tin4.c",
]));
  set("light_up", 1);

  setup();
}
