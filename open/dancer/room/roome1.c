// Room: /open/dancer/room/roome1.c :cgy

inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
夜梦小筑的走廊，一路向东接连，北面的墙上有着美丽的
雕塑，走到这里你闻到阵阵花香，原来你已经接近夜梦小筑的
花园了，西边是夜梦大殿。


LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"start",
  "east" : __DIR__"roome2",
  "north" :__DIR__"roomen1",
]));

  set("light_up", 1);

  setup();
}
