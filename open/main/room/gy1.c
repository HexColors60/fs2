inherit ROOM;

void create ()
{
  set ("short", "沙漠尽头");
  set ("long", @LONG
你来到了撒哈拉沙漠的尽头，阵阵风飞沙吹的你眼睛
无法看清楚前方，但依然可以听到交谈声，东边似乎有些
人正在卖命工作着。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"d7.c",
/*
  "east" : "/open/island/room/port",
*/
]));
  set("outdoors", "/open/main");

  setup();
}

