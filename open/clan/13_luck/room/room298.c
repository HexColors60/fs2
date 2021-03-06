inherit ROOM;
void create() {
	set( "short", "世间雷道" );
	set( "object", ([
		"amount3"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/mon/obj/ghost-legging",
		"file9"    : "/open/mon/obj/ghost-legging",
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount10" : 1,
		"amount5"  : 1,
		"file8"    : "/open/mon/obj/ghost-helmet",
		"file7"    : "/open/wind-rain/obj/sun_red_cloth",
		"file6"    : "/open/mon/obj/ghost-legging",
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount8"  : 1,
		"file1"    : "/open/mon/obj/ghost-legging",
		"file10"   : "/daemon/class/fighter/figring",
		"amount1"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
	]) );
	set( "build", 10236 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room297.c",
		"south"     : "/open/clan/13_luck/room/room322",
		"east"      : "/open/clan/13_luck/room/room299.c",
		"north"     : "/open/clan/13_luck/room/room269",
	]) );
	set( "long", @LONG

    沧桑岁月，世间常变，来到这条十三吉祥的世间五候道，此道为[33m雷[0m
[33m道[0m，用来比喻十三吉祥的威力，而此道上面都放着给帮众的防具与武器
，而适用对象为，没时间打防具跟武器的帮众，与新进帮众没能力打防
具与没自己的房间可以借用一下。

LONG);
	setup();
	replace_program(ROOM);
}
