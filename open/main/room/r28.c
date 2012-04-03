// Room: /open/main/room/r28.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set("long", @LONG
出了中央驿站，往东是一条笔直的道路，北方是
一座台地，但这儿没有路可以上去，南方则是横亘大
陆中央的天山山脉的一部份，壮观的景色令人叹为观
止。可惜四处都找不到路可以上。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"r27",
  "east" : __DIR__"r29",
]) );
  set("outdoors", "/open/main" );     
  setup();
}
