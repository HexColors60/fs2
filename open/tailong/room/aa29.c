inherit ROOM;

void create ()
{
  set ("short", "北院走廊");
  set ("long", @LONG
走到这里,发现北院的围墙沿着山壁向北延伸出去,同时也有一条通
往北方的岔路,向北望去好像有一座高塔,不知道里面有什么东西。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"aa28",
  "north" : __DIR__"aa55",
  "east" : __DIR__"aa30",
]));

  setup();
  replace_program(ROOM);
}
