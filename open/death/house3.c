// Room: /open/death/house3.c

inherit ROOM;

void create ()
{
  set ("short", "鬼屋");
  set ("long", @LONG

这是一间什么都没有的房间test
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wroad",
]));
  set("no_fight", 1);
  set("light_up", 1);
  set("no_magic", 1);

  setup();
}
