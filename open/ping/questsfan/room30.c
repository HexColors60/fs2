// Room: /u/d/dhk/questsfan/room30
inherit ROOM;

void create ()
{
  set ("short", "虹晶桥后段");
  set ("long", @LONG
晶桥的后半段可能因为越来越接近另一岸了，同时也
较远离断崖中心了，其强劲的吸引力也缓和下来了。当你
踏到陆地的那一刹那、百感交集俨然觉得刚从鬼门关走了
一遭，但幸运的逛了回来了。哎！踩在陆地上的感觉真踏
实啊！！！

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "godown" : __DIR__"room8",
  "fly" : __DIR__"room29",
]));
  set("outdoors", "/u/d");

  setup();
}
