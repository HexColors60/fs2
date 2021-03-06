// Room: /open/badman/room/b8
inherit ROOM;

void create ()
{
  set ("short", "恶人谷北人街");
  set ("long", @LONG
你发现北街上人群来来往往，似乎比南街热闹的多，因为这边
是恶人谷日常生活的重心，包管全恶人谷的吃喝玩乐。看到人们脸
上轻松的表情，你紧绷的神经也稍稍舒缓的下来。或许你可以放松
心情好好的逛一逛。
    你看到西边有一家小饭馆，正敞开大门等待着你的光临。
    大街往南北方延伸。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"r1",
  "south" : __DIR__"b4",
  "north" : __DIR__"b9",
]));
  set("outdoors", "/open/badman");

  setup();
}
