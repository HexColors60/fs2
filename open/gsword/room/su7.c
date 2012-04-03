// Room: /open/gsword/room/su7.c

inherit ROOM;

void create ()
{
  set ("short", "青石小径");
  set ("long", @LONG
走在青石小径上,这里已不是蜀中闹区,高大的建筑渐渐减少,取代
的是一般平房,你西方有一潭清水,正是闻名的蜀中昆明湖.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : "/open/gsword/room/suroom0",
  "west" : "/open/gsword/room/lake2",
  "south" : "/open/gsword/room/su6",
]));

  set("outdoors", "/open/gsword");

  setup();
}
