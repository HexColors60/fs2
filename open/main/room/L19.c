// Room: /open/main/room/L19.c

inherit ROOM;

void create()
{
	set("short", "台地");
	set("long", "这是一块微微高起的台地，稀稀疏疏的长了起几丛杂草，
几块石块杂乱分部，更显得这里的荒凉.
");

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"L16",
  "south" : __DIR__"r47",
  "west" : __DIR__"r45",
  "east" : __DIR__"L20",
]) );

  set("outdoors", "/open/main" );


  setup();
}
