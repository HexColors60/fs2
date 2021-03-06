// Room: /open/main/room/s21.c

inherit ROOM;

void create ()
{
  set ("short", "草原");
  set ("long", @LONG
	这里是御林军专用的操练场，由于乃军机重地，
	故守卫十分的森严，周围用栅栏围了起来，入口
	前有块告示碑(marker)。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "marker" : "			军机重地

		      非洽公要务，
		立    入    者    斩！

			三品御前带刀御林军军长  霍拔

",
]));

  set("objects", ([ /* sizeof() == 2 */
  "/open/center/npc/brownhorse" : 1,
  "/open/center/npc/blackhorse" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"s17",
  "west" : __DIR__"s20",
  "east" : __DIR__"s22",
]));

  setup();
}
