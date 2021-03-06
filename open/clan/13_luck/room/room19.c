inherit ROOM;
void create() {
	set( "short", "青龙盘天" );
	set( "owner", "mad" );
	set( "object", ([
		"file10"   : "/open/mon/obj/ghost-helmet",
		"file4"    : "/open/ping/obj/chilin_legging",
		"amount9"  : 1,
		"file9"    : "/open/ping/obj/iceger",
		"file7"    : "/open/ping/obj/ring-2",
		"amount2"  : 1,
		"amount10" : 1,
		"amount7"  : 1,
		"amount4"  : 1,
		"file8"    : "/open/mon/obj/ghost-cloak",
		"file6"    : "/open/ping/obj/iceger",
		"amount1"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/ping/obj/chilin_legging",
		"file2"    : "/daemon/class/blademan/obj/shield",
		"amount6"  : 1,
		"file1"    : "/open/mogi/castle/obj/lochagem",
		"amount3"  : 1,
		"amount8"  : 1,
		"file3"    : "/open/ping/obj/gold_hand",
	]) );
	set( "build", 13842 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room18.c",
		"up"        : "/open/clan/13_luck/room/room20",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    经过了青龙殿之后看到了青色的阶梯盘旋向上延伸，宛如一条青龙
往天际直飞而去，看到阶梯入口有士兵把守着就觉得通往上面的地方是
个重要之地，守卫每一个人都严肃的站岗着，除非有帮主给的通行证，
不然想硬闯你就准备血溅当场吧。

LONG);
	setup();
	replace_program(ROOM);
}
