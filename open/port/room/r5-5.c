// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","渔户");
  set ("long", @LONG
这是一间简陋的平房 , 房子仅简单的摆着一些家具 . 墙壁
十分的破旧 , 随时都有倒塌的可能 , 你很难想像在富庶的枫林
港内竟然会有这种房子 , 不过看到他们脸上洋溢的笑容 , 似乎
过的比任何人都快乐呢 !

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
	"south" : "/open/port/room/r5-3",
]));
	set("objects",([
	"/open/port/npc/boy":1,
	"/open/port/npc/wangma":1,
	]));

  setup();
}
