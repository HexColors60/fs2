// Room: /open/capital/room/r33.c

inherit ROOM;

void create ()
{
  set ("short", "永安胡同");
  set ("long", @LONG
北边便是是京城里的衙门, 门口的两尊石狮子放在两旁, 显的十分
的雄壮威武。路边有个告示牌，一群人围在那看着，多半是看些江洋大
盗的缉捕令，有时候也有些犯人斩首示众的消息，一些闲得发慌的人们
最喜欢聚在此地指东道西，高谈阔论。
    这里有禁卫军四处的巡逻着，所以你还是不要在城内惹事的好。

LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/capital/obj/board" : 1,
  "/open/capital/npc/walker2" : 1,
]));
  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"r31",
  "north" : "/open/hall/halldoor",
  "east" : __DIR__"r34",
]));
  set("gopath", "west");
  set("gopath2", "west");

  setup();
}
