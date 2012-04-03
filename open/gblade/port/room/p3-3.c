// Room: /open/gblade/port/room/p3-3.c
inherit ROOM;

void create ()
{
  set ("short", "港口");
  set ("long", @LONG
这里就是港口了 , 不过你无法从这里搭船 , 南边是一片茫
茫的大海 , 一望无际 , 似乎充满了各种危险 , 却也满是新奇的
事物 , 你真想搭船出去 , 到各地去闯一闯 .

LONG);

  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"p3-2",
]));

  setup();
}
