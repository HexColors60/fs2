inherit ROOM;

void create ()
{
  set ("short", "南堂风");
  set ("long", @LONG
不知道是不是迷信的关系，总觉得有一道冷风从背脊游走过，身
体不自然的颤抖着，难道是这里有怪东西吗？但是除了书本以外，再
也没有其它奇怪的东西了。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wind",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/scholar_wind.c" : 1,
]));

  setup();
}
