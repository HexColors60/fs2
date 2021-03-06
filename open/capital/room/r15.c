// Room: /open/capital/room/r15.c

inherit ROOM;

void create ()
{
  set ("short", "东城门下");
  set ("long", @LONG
这里是兵马常进出的地方，不要在此地逗留，以免遭受到不必要的
伤害，徒惹是非。
    西方的大道通往皇宫大门, 也可连至京城里最富裕的区域。
    往北则是通往大理寺的路。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/soldier" : 1,
]));

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
   "north":"/open/capital/room/chen_home",
  "west" : __DIR__"r14",
  "east" : __DIR__"D02",
]));

  set("gopath", "west");

  setup();
}
