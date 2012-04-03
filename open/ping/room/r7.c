// Room: /u/m/moner/open/room/r7.c 
inherit ROOM;
 
void create ()
{
  set ("short", "一楼楼梯");
  set ("long", @LONG

    往上可以通往二楼, 楼梯的扶手和整座楼梯都是选用上等木材制造的
它的雕工精细的让你真是叹为观止, 楼梯的两旁也挂满了火把。


LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"r4.c",
  "west" : __DIR__"room14.c",
]));

  setup();
  replace_program(ROOM);
}
