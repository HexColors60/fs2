// Room: /u/m/moner/open/room/r3.c 
inherit ROOM;
 
void create ()
{
  set ("short", "三楼楼梯");
  set ("long", @LONG

往下可以回到二楼, 楼梯的扶手和整座楼梯都是选用上等木材制造的,
它的雕工精细的让你真是叹为观止, 往西是三楼的走廊。


LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r2.c",
  "down" : __DIR__"r4.c",
]));

  setup();
replace_program(ROOM);
}
