// Room: /u/p/poloer/dragon/c3
inherit ROOM;

void create ()
{
  set ("short", "炎龙谷后段");
  set ("long", @LONG
来到了后段就必须更加小心，也就是越靠近凶恶的谷主啰。四周
突然比较有生气起来，可以看到些小动物了，但不禁怀疑这是诱敌的
技巧吗?

LONG);

  set("outdoors", "/u/p");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"c1",
]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}
