// Room: /open/ping/room/m14.c ~night~(小恋)

inherit ROOM;

void create ()
{
  set ("short", "小地道");
  set ("long", @LONG


这个地道一定就是通往风行山的路了,把地道做的这么隐密,除了山上那些山贼外,大概没有
人这么无聊了,如果你想见识一下风行山贼的蠢样,就继续走下去吧!

LONG);

  set("objects", ([ /* sizeof() == 1 */
]));

  set("outdoors", "/open/ping");

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"m15",
  "east"  : __DIR__"m13",
]));

  setup();
}
