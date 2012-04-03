// Room: /open/capital/room/h06.c

inherit ROOM;

void create ()
{
  set ("short", "扁鹊胡同");
  set ("long", @LONG
步入扁鹊胡同, 两旁柳树摇曳, 四处都扫的干干净净。仔细的嗅一
嗅, 空气中似乎弥漫着一股浓郁的药味, 这时你才发现原来南边就是一
家药店, 招牌上写的是「仁心药店”, 里头还有不少人正在抓药的样子
。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"medical",
  "west" : __DIR__"r67",
  "east" : __DIR__"h08",
]));
  set("outdoors", "/open/capital");

  setup();
}
