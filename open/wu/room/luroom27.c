// Room: /open/wu/room/luroom27.c
// 泷山内院走道
inherit ROOM;
void create ()
{
  set ("short", "内院");
  set ("long", @LONG
这里是泷山武馆内的后院,一眼望去看到有许多的厢房,后院
内种植许多的花草树木,井然有序,西边是通往泷山派的禁地
北边是通往厢房,走道从东边延升下去。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"luroom25.c",
  "north" : __DIR__"luroom28",
  "east" : __DIR__"luroom29",
]));

  setup();
}
