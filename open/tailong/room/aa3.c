// Room: /u/o/ookami/newarea/aa3.c 
inherit ROOM;
 
void create ()
{
  set ("short", "点苍山腰");
  set ("long", @LONG
你已经走到点苍山的山腰上,深深的吸一口气,这里的空气比平地好
多了,环顾四周,到处都是高大的树木,往
西北有一条白石小径
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"aa2.c",
  "northwest" : __DIR__"aa4",
]));
  set("outdoors", "/u/o/ookami/newarea");

  setup();
  replace_program(ROOM);
}
