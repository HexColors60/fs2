inherit ROOM;
void create() {
	set( "short", "八楼走道" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room205",
		"up"        : "/open/clan/13_luck/room/room203",
	]) );
	set( "long", @LONG

　　你小心异异的走在龙塔之中，里面的石壁排列几乎都是同一个样
子，一不小心就会迷失其中，看来不小心是不行了，正当你左右顾盼
，小心翼翼往前继续前进之时，突然六道影子向你俯冲而来，挡住你
的去路，定神一看，天ㄚ～竟然是烈焰之龙！！

LONG);
	setup();
	replace_program(ROOM);
}
