// Room: /u/r/red/room/flower.c
inherit ROOM;

void create ()
{
  set ("short", "北厢房");
  set ("long", @LONG
这是计谋厅老师的厢房，只见房中桌上十分的凌乱，桌上尽放置
着许许多多不同的地形图，仔细观看地形图上有着许许多多的记号
，便可知道老师多么专研于计谋之使用。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"w3.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/plan_teacher.c" : 1,
]));

  setup();
}
