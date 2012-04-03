// Room: /open/main/room/maiu-1.c
inherit ROOM;

void create ()
{
  set ("short", "澜苍江畔");
  set ("long", @LONG

这里是澜沧江畔的陡涯,澜沧江就在你脚下的深谷里  ◇◆───────┐
,往下一望,只见江水涛涛,非但赤脚难以涉水走过,   ◆                │
就是行舟,也未必渡的过这涛天江水,你西边有一座   │    西域往北    │
吊桥,高高的横过江面.                           │                ◆
  往北走通往〔西域〕                           └────歧路人◆◇

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : "/open/prayer/room/westarea/road37",
  "east" : __DIR__"r41",
  "south" : __DIR__"to_chun1.c",
  "west" : __DIR__"maiu-2",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/murofu" : 1,
]));
  set("资源", ([ /* sizeof() == 1 */
  "液体" : ([ /* sizeof() == 3 */
      "止渴" : 30,
      "名称" : "清水",
      "种类" : "水",
    ]),
]));
  set("outdoors", "/open/ping");

  setup();
}
