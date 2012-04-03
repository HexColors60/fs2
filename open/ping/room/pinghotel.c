// Room: /open/ping/room/pinghotel.c
inherit ROOM;

void create ()
{
  set ("short", "平南客栈");
  set ("long", @LONG
这里是平南城最大的客栈,许多旅客都在这里修息,你也可以
在这里买些小吃,填饱你饥肠碌碌的肚子.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road2",
]));
  set("light_up", 1);

  setup();
}
