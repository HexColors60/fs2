// room:open/doctor/room/d7.c made by adam..

inherit ROOM;

void create ()
{
	set("short","走廊");
  set ("long", @LONG
这里是银针门的东走廊，一路走来，你不禁对南方的花
园产生极大的好奇心，带着兴奋的心情，迫不及待的要去看
看到底种了什么东西 ？

LONG);

  set("light_up", 1);
	
	set("objects",([
 	]));
  set("exits", ([ /* sizeof() == 2 */
      "south" : __DIR__"d10",
      "west" : __DIR__"d6",
      ]));
  setup();
}
