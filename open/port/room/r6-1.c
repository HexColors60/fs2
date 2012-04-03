// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","城墙边");
  set ("long", @LONG
你正走在一条小巷上 . 当初在建造城墙时 , 即在房屋和城
墙之间预留了七步的空间 , 可容车马往来 . 墙壁是由砖石所砌
成 , 高数十尺 , 从这里可以看到城墙上有数名守卫正在巡逻着

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"west" : "/open/port/room/r1-2",
	"east" : "/open/port/room/r6-2",
]));
	set("objects",([
	]));

  setup();
}
