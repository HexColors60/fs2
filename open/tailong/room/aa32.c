inherit ROOM;

void create ()
{
  set ("short", "右侧走廊");
  set ("long", @LONG
这里是连接中庭和大雄宝殿的右侧走廊,向北直走就是往大雄宝殿
的方向,往南则是中庭,往东的一条小径则是通往一个花园。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"aa8",
  "north" : __DIR__"aa34",
  "east" : __DIR__"aa50",
]));

  setup();
  replace_program(ROOM);
}
