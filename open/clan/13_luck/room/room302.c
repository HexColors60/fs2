inherit ROOM;
void create() {
	set( "short", "世间土道" );
	set( "object", ([
		"amount3"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/mogi/castle/obj/lochagem",
		"file7"    : "/open/mogi/castle/obj/lochagem",
		"amount5"  : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/mogi/castle/obj/lochagem",
		"amount4"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"file3"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "build", 12087 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room303.c",
		"south"     : "/open/clan/13_luck/room/room314",
		"north"     : "/open/clan/13_luck/room/room275.c",
	]) );
	set( "long", @LONG

    沧桑岁月，世间常变，来到这条十三吉祥的世间五行道，此道为[33m土[0m
[33m道[0m，用来比喻十三吉祥的稳固，而此道上面都放着给帮众的防具与武器
，而适用对象为，没时间打防具跟武器的帮众，与新进帮众没能力打防
具与没自己的房间可以借用一下。

LONG);
	setup();
	replace_program(ROOM);
}
