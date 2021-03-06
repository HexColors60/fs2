// Room: /open/main/room/r29.c

inherit ROOM;

void create ()
{
  set ("short", "道路");
  set ("long", @LONG
	道路从这开始转向北方延伸，遥远的北方似乎是座森林，
	南方是高低起伏的丘陵地，东方则是一片无垠的草原，传
	说在西北方的高地上有座雪苍山，是武者的发源地，但这
	里没有路可以上去。


LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/obj/torch" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 4 */
  "southup" : __DIR__"m18",
  "west" : __DIR__"r28",
  "north" : __DIR__"r20",
  "east" : __DIR__"s19",
]));

  setup();
}
