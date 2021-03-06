inherit ROOM;
void create() {
	set( "short", "练刀房" );
	set( "object", ([
		"file3"    : "/open/mon/obj/ghost-legging",
		"amount1"  : 1,
		"file7"    : "/open/mon/obj/ghost-cloak",
		"amount7"  : 1,
		"file9"    : "/open/mon/obj/ghost-cloak",
		"amount10" : 1,
		"file6"    : "/open/mon/obj/ghost-helmet",
		"file1"    : "/open/mon/obj/ghost-legging",
		"file8"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
		"file10"   : "/open/mogi/castle/obj/fire_book",
		"amount9"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount2"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"file5"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "build", 11703 );
	set( "light_up", 1 );
	set( "owner", "holeman" );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room305",
	]) );
	set( "long", @LONG
处在这房间令你浑身不自在，因为这房间完全没有摆设，取
而代之的是四面由钢铁所打造成的墙壁，而这些坚硬的墙壁
上却被刻上无数的刀痕。当你碰触其中一道刀痕时，没想到
在脑海中突然浮现出一个人向你演练一式刀招，原来这些刀
痕上都残留着每一式刀招的刀意。但没想到这些刀招却太博
大精深，不管你怎么练都无法抓到其中的精髓，看来这些刀
招的主人一定是位在世高人啊。
LONG);
	setup();
	replace_program(ROOM);
}
