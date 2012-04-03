// Room: /u/o/ookami/newarea/aa2.c 
inherit ROOM;
 
void create ()
{
  set ("short", "点苍山腰");
  set ("long", @LONG
你已经走到点苍山的山腰上,深深的吸一口气,这里的空气比平地好
多了,环顾四周,到处都是高大的树木,往西有一条白石小径,看起来像是
有人刻意铺设的,不妨沿着小径走,看看会有什么奇遇
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"aa3.c",
  "down" : __DIR__"aa1",
]));
  set("outdoors", "/u/o/ookami/newarea");

  setup();
  replace_program(ROOM);
}
