// Room: /open/main/room/r2.c

inherit ROOM;

void create()
{
	set("short", "道路");
	set("long", "这里是从驿站通往北卢关必经的要道, 四周的景色实在是令人
永生难忘, 沙漠草原沼泽群集, 路上不时出现稀奇古怪的生物来。
");

  set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"r1",
  "southeast" : __DIR__"p1",
  "southwest" : __DIR__"r3",
  "northwest" : __DIR__"d9",
]) );

  set("outdoors", "/open/main" );

  setup();
}
