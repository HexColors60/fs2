// Room: /u/p/pokai/room/wu/l
inherit ROOM;

void create()
{
  set ("short", "武威七杀塔二楼--");
  set ("long", @LONG
踏入这儿给你的第一个印象，还是那片恼人的暗红色，和着地上斑斑的
血迹，使你觉得这儿充满一片血腥，不禁有一股冲动想要往回走。
LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tower2-3",
  "north" : __DIR__"tower2-1",
]));
  setup();
}
