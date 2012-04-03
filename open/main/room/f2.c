// Room: /open/main/room/f2.c

inherit ROOM;

void create()
{
	set("short", "森林");
	set("long",@LONG 
  这看起来是一望无际的森林，东边黑压压的一片密林
      看来像是人烟稀少的地方...
LONG);

  set("outdoors", "/open/main" );

  set("objects",([
      "/open/main/npc/mechoufen" :1,
     ]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"f4",
  "west" : __DIR__"f1",
  "east" : __DIR__"F1",
]) );

  setup();
}
