inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG
除了那个守卫外 ,这里真是再平凡不过了 ,东边是一所农家的院
子 ,你可以试着到里面看看 ,看看有没有人能告诉你 ,这里到底
是啥地方 .北边哗啦哗啦 ,好像有流水的声音 .

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"room28",
  "north" : __DIR__"room26",
  "south" : __DIR__"room24",
]));
  setup();
}


