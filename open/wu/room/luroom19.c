// Room: /open/wu/room/luroom19.c
// 泷山武馆内道
inherit ROOM;
void create ()
{
  set ("short", "走道");
  set ("long", @LONG
这里是泷山武馆内的走道,往东的话是通往泷山派的禁地及内院,
而南边是泷山派的祠堂,往西走的话则是回到泷山派的大厅。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"luroom22",
  "west" : __DIR__"luroom18",
  "east" : __DIR__"luroom20",
]));
  set("light_up", 1);

  setup();
}
