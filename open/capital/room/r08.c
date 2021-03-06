// Room: /open/capital/room/r08.c

inherit ROOM;

void create ()
{
  set ("short", "环宫大道");
  set ("long", @LONG
往北是进出皇宫的唯一通道, 但若不是什么皇亲国戚或是文武百官
等大人物, 是不准平常老百姓进出的。南方有道楼梯, 直通一座高台,
是皇帝祭祖、昭告的地方, 你想上去瞧瞧吗?

LONG);

  set("outdoors", "/open/capital");
  set("objects", ([ /* sizeof() == 2 */
  "/open/capital/npc/cleanman" : 1,
  "/open/start/npc/any" : 1,
]));
  set("exits", ([ /* sizeof() == 5 */
  "north" : __DIR__"D04",
  "west" : __DIR__"r07",
  "southup" : __DIR__"tower",
  "east" : __DIR__"r09",
  "south" : __DIR__"r74",
]));
  set("gopath", "east");

  setup();
}
