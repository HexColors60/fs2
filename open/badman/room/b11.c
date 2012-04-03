// Room: /open/badman/room/b11
inherit ROOM;

void create ()
{
  set ("short", "恶人谷北地街");
  set ("long", @LONG
你发现北街上人群来来往往，似乎比南街热闹的多，因为这边
是恶人谷日常生活的重心，包管全恶人谷的吃喝玩乐。看到人们脸
上轻松的表情，你紧绷的神经也稍稍舒缓的下来。或许你可以放松
心情好好的逛一逛。

LONG);

   set("objects", ([ /* sizeof() == 1 */
  // "/open/badman/npc/blind.c" : 1,
]));
  set("outdoors", "/open/badman");
   set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"b12",
  "east" : __DIR__"b10",
]));

  setup();
}
