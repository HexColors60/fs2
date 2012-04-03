// Room: /open/poison/room/v6.v
inherit ROOM;

void create ()
{
  set ("short", "农舍");
  set ("long", @LONG
一间普普通通以砖瓦盖成的屋子，这是供给村民所住的农舍，
里面陈设十分简单，没有甚么能引起你兴趣的东西。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"v2-2.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 2 */
  "/open/poison/npc/child.c" : 1,
  "/open/poison/npc/vler2.c" : 1,
]));

  setup();
}
