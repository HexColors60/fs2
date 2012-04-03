// Room: /u/m/moner/room/room16.c
inherit ROOM;

void create ()
{
  set ("short", "内房");
  set ("long", @LONG

经过蜿埏的长廊后, 你来到了内房, 往东私乎是某人的卧房, 往东通
往书房, 往南是水云轩。轻罗纱窗外飘着朵朵的白云, 淡淡的翠竹叶延
伸至室内, 一种飘渺的感觉袭上你的心头。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room17.c",
  "north" : __DIR__"room10.c",
]));
  set("light_up", 1);

  setup();
}
