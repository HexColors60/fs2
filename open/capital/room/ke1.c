// Room: /open/capital/room/ke1.c
inherit ROOM;

void create ()
{
  set ("short", "干通天府");
  set ("long", @LONG
这理就是大名顶顶的干通天所住的豪宅, 前门站的两个守门的, 由此
可看出干通天的势力可以跟一些将士王侯差不多。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"r18.c",
]));
  set("outdoors", "/open/capital");

  setup();
}
