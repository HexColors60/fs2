inherit ROOM;

void create ()
{
  set ("short", "大雄宝殿");
  set ("long", @LONG
这里就是天龙寺的正殿--大雄宝殿,挑高八米八,全部的柱子都是
用上好的大理石材所制,柱子上有栩栩如生的雕刻,而梁木是用南部高
上特产的红桧所制成,富丽堂皇。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"aa43",
  "south" : __DIR__"aa37",
  "west" : __DIR__"aa39",
]));
}
