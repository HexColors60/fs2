// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","刀客交谊厅");
  set ("long", @LONG
这里是刀客们平时聊天 , 打屁的地方 . 四周摆了几张桌椅
 , 你可以在此好好的休息一下 . 由于其他职业的人不能进来 ,
很多资深的刀客会放些装备在此 , 以照顾后辈 .

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
	"north" : "/open/port/room/r4-6",
]));
	set("objects",([
	]));

  setup();
}
