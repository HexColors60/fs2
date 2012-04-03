// Room: /u/p/poloer/dragon/b1
inherit ROOM;

void create ()
{
  set ("short", "炎龙谷中段");
  set ("long", @LONG
来到了这里，四周看起来更加的诡异，有点想退缩的感觉。
这里的杀气很重，让人感觉到非常的难过，同时也感觉到很想杀
人。周围尽是一些死人的骇骨，使人不禁退后三步。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mob4.c" : 2,
]));
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"b4",
  "up" : __DIR__"ring3",
  "south" : __DIR__"b2",
]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}
