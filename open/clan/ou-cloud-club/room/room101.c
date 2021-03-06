inherit ROOM;
void create() {
	set( "short", "$HIG$丹$HIM$药$HIC$房$NOR$" );
	set( "object", ([
		"amount6"  : 287,
		"amount8"  : 95,
		"file4"    : "/open/mogi/castle/obj/sspill",
		"amount3"  : 126,
		"amount4"  : 400,
		"file10"   : "/open/mogi/castle/obj/sspill",
		"amount10" : 83,
		"file1"    : "/open/fire-hole/obj/p-pill",
		"amount1"  : 800,
		"file2"    : "/open/fire-hole/obj/k-pill",
		"file9"    : "/open/marksman/obj/super_pill",
		"file5"    : "/open/fire-hole/obj/b-pill",
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"amount2"  : 101,
		"amount7"  : 38,
		"file6"    : "/open/fire-hole/obj/r-pill",
		"file3"    : "/open/fire-hole/obj/w-pill",
		"file8"    : "/open/mogi/dragon/obj/power",
		"amount9"  : 1000,
		"amount5"  : 1173,
	]) );
	set( "owner", "enter" );
	set( "build", 10605 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room231",
		"east"      : "/open/clan/ou-cloud-club/room/room4.c",
	]) );
	set( "long", @LONG
从你踏入此室时，一股淡淡清香扑鼻而来，只见地上
堆积着一堆堆的药草，都是江湖上梦寐以求的药草，而墙
边壁橱内更是放满着各式各样的药丹，每一样都是稀有难
求的，而此处竟堆积着如此多的丹药，若非亲眼看见还真
无法相信，可见傲云山庄里拥有太多的高手存在了。

LONG);
	setup();
	replace_program(ROOM);
}
