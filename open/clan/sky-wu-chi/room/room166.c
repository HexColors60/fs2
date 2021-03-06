inherit ROOM;
void create() {
	set( "short", "山间小路" );
	set( "object", ([
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
		"file9"    : "/open/ping/obj/gold_hand",
		"amount2"  : 1,
		"file4"    : "/open/dancer/obj/maple_ribbon",
		"amount6"  : 4,
		"amount3"  : 1,
		"amount9"  : 1,
		"file2"    : "/open/killer/obj/k_ring",
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"file10"   : "/open/ping/obj/chilin_legging",
		"file5"    : "/daemon/class/dancer/bee_flute",
		"file6"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 1,
		"amount10" : 1,
		"amount1"  : 31,
		"file7"    : "/daemon/class/blademan/obj/shield",
		"file1"    : "/open/marksman/obj/super_pill",
		"amount8"  : 1,
		"amount7"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10880 );
	set( "owner", "herononame" );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"south"     : "/open/clan/sky-wu-chi/room/room163",
	]) );
	set( "long", @LONG
这里是翠峰的山脚下，听附近的居民说这里不但风景美
丽，据说还有神仙出没喔，因此你怀着朝圣般的心情来到这
，心中期盼能看到传说中的神仙，走在山间的小路上，心中
响起了村中孩童所说的话：‘上次我在山上看到一位美丽的
大姐姐耶，她跳的舞好好看喔，就像仙女下凡一样’，想到
这，你不禁加快了脚步，往山上走去。
LONG);
	setup();
	replace_program(ROOM);
}
