// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","东大街");
  set ("long", @LONG
你正走在东大街上 , 这一带是枫林的住宅区 , 不过街道两
旁仍然有些店铺 . 北边大屋传来了朗朗的读书声 , 那是一家学
堂 , 如果你大字不识一个 , 赶紧过去看看吧 !

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"west" : "/open/port/room/r3-2",
	"east" : "/open/port/room/r3-4",
	"north" : "/open/port/room/r3-5",
]));
	set("objects",([
	]));

  setup();
}
