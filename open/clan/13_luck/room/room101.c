inherit ROOM;
void create() {
	set( "short", "凤凰楼五楼" );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room102.c",
		"north"     : "/open/clan/13_luck/room/room183.c",
		"up"        : "/open/clan/13_luck/room/room100.c",
		"south"     : "/open/clan/13_luck/room/room196.c",
		"east"      : "/open/clan/13_luck/room/room231.c",
		"west"      : "/open/clan/13_luck/room/room240",
	]) );
	set( "long", @LONG

    在店小二的引领，你沿着灯火照亮的楼梯往上爬，来到了凤凰楼
五楼的通道，往你的厢房走去。从窗口往西边的窗口望去，那里是帮
主小南费心建造的‘虚拟海洋’，放眼望去一片汪洋大海，一但进入
，想要在出来，那可是要花费好大一番功夫才有办法找到出口。

LONG);
	setup();
	replace_program(ROOM);
}
