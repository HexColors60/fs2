// Room: /open/capital/room/premier
inherit ROOM;

void create ()
{
  set ("short", "丞相府前庭院");
  set ("long", @LONG
踏进了丞相府门口, 是一处庭院, 流水假石, 草木扶疏, 水声淙淙
, 简直巧夺天工, 另你叹为观止, 中间的一条路直直的通往一栋屋子的
大门。这里的设计便是皇宫里的工匠亲自量造的, 听说是皇上特地命人
如此的, 由此可知当今宰相是如何受到皇上爱惜。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/capital/room/r63",
]));

  setup();
}
