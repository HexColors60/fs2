// /u/j/judd/room/r13.c
inherit ROOM;

void create ()
{
  set ("short", "中堂西侧");
  set ("long", @LONG
这里是中堂的角落，也是通往火室图书馆的必经道路，地上有一
条红色的道路一直通往西北，东边则可通往后厅休息处，火室图书馆
到底是放些什么书呢？这个问题，只有自己去看看才知道，只要沿着
那条红色的路就可以了。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r16.c",
  "northwest" : __DIR__"r10.c",
]));
  set("light_up", 1);

  setup();
}
