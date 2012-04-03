// Room: /open/gsword/room/north
inherit ROOM;

void create ()
{
  set ("short", "长廊");
  set ("long", @LONG
这里已经算是仙剑派的内部了，一般若非剑派的人只能就此止步，
从这往北是剑士们练剑的场所，往西是用膳及师兄弟们的住处，东
边则是典藏着武学秘笈的藏经阁。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : "/open/gsword/room/ghouse",
  "west" : "/open/gsword/room/eghouse",
  "north" : "/open/gsword/room/nghouse",
  "east" : "/open/gsword/room/wghouse.c",
]));

  set("light_up", 1);

  setup();
}
