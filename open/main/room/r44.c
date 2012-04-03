// Room: /open/main/room/r44.c

inherit ROOM;

void create ()
{
  set ("short", "石子小路");
  set ("long", @LONG
这是一条小小的石子小径，不仔细搜寻，你还不知道有这
，道路通往东西方，可是谁也不晓得它往那走.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"L25",
  "west" : __DIR__"r43",
  "north" : __DIR__"f19",
	"east":"/open/main/room/[3]",
]));
  set("outdoors", "/open/main");

  setup();
}
