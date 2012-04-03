// Room: /open/death/bridge3.c

inherit ROOM;

void create ()
{
  set ("short", "奈何桥尾");
  set ("long", @LONG
这里已经是奈何桥的桥尾了，再往前走就要进鬼门关了，鬼门关前排
了好长的队伍，队伍里大致上有三种人，一种是魂魄出窍，来地府观光的
，另外一种就是阳寿已尽，而被钩魂使者带过来的，最后一种，就是像你
这种孤魂野鬼，死后没地方去，只好来地府报到的。
LONG);
  set("no_auc",1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bridge2",
  "north" : __DIR__"gate",
]));
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("no_transmit", 2);

  setup();
}
