// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","中央大街");
  set ("long", @LONG
你正走在中央大街上 , 南边就是港口了 . 这里已经濒临着
海岸 , 几个码头往难延伸出去 , 商用的 , 客运的 , 分的井然
有序 , 港口繁忙却不紊乱 . 西边是个小渔村 , 东边则是水军
军营 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 4 */
	"east" : "/open/gblade/navy/room/d1-1",
	"west" : "/open/port/room/r5-2.c",
	"north" : "/open/port/room/r2-2",
        "south" : "/open/dancer/room/fonport", 
]));
	set("objects",([
	]));

  setup();
}
