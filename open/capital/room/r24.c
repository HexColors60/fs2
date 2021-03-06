// Room: /open/capital/room/r24.c

inherit ROOM;

void create ()
{
  set ("short", "日落驰道");
  set ("long", @LONG
东边有条小路衔接在驰道上。路旁立了根小木牌上面写着‘芙蓉湖’
。正想着要不要过去瞧瞧的同时，有一群水鸟从湖的方向飞向天际，更
加使你有去瞧瞧这湖的冲动。

LONG);

  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"r25",
  "north" : __DIR__"r23",
  "east" : __DIR__"lake1",
]));
  set("gopath", "north");

  setup();
}
