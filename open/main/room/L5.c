// Room: /open/main/room/L5.c

inherit ROOM;

void create ()
{
  set ("short", "台地");
  set ("long", @LONG
这是一块微微高起的台地，稀稀疏疏的长了起几丛杂草，
几块石块杂乱分部，更显得这里的荒凉.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/main/room/L7",
  "eastup" : "/open/main/room/M21",
]));

  set("outdoors", "/open/main");

  setup();
}
