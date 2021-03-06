// Room: /open/start/room/s5.c

inherit ROOM;

void create ()
{
  set ("short", "凌云村");
	set( "build", 1147 );
  set ("long", @LONG
平静安详的村庄，两旁见到的都是平凡的民舍，
没有什么特殊的建筑，远向南方望去是一片绿油油的
稻田，有几个农夫正在辛勤的耕作。
你注意到新立了个路标 (sign) 。

LONG);
  set("item_desc", ([ /* sizeof() == 1 */
	"sign" : @ITEM
儒门由此往南二, 往西, 往南六, 往西, 往南
ITEM,
  ]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/start/npc/vendor" : 1,
]));
  set("outdoors", "/open/start");
  set("exits", ([ /* sizeof() == 4 */
  "west" : "/open/start/room/s4",
  "south" : "/open/start/room/s8",
  "north" : "/open/start/room/s9",
  "east" : "/open/start/room/s10",
]));

  setup();
}
