inherit ROOM;
void create() {
	set( "short", "混世间的小屋" );
	set( "owner", "aszyzit" );
	set( "object", ([
		"file3"    : "/open/wind-rain/obj/sun_red_cloth",
		"file9"    : "/open/killer/memory/static",
		"file1"    : "/open/killer/memory/static",
		"amount5"  : 1,
		"amount7"  : 1,
		"amount2"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/killer/memory/static",
		"amount3"  : 1,
		"file5"    : "/open/tendo/obj/chaosbelt",
		"amount1"  : 1,
		"file6"    : "/daemon/class/fighter/figring",
		"file4"    : "/open/mogi/dragon/obj/power",
		"amount4"  : 24,
		"amount6"  : 1,
		"file7"    : "/open/port/obj/wolf_ring",
	]) );
	set( "build", 10119 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room54.c",
		"enter"     : "/open/clan/13_luck/room/room120",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    一进房间，又看到那每天熬夜的可恨十米 chamber，里面又是那
些天线，turntable每天就是有做不完的测试EMI跟 debug，在现在的
环境下，也未尝不是一份不错的工作...

        也鼓励自己；努力坚持到最后，人生有梦你会红..

LONG);
	setup();
	replace_program(ROOM);
}
