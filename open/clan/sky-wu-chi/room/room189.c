inherit ROOM;
void create() {
	set( "short", "凤无双的刑求室" );
	set( "object", ([
		"amount4"  : 1,
		"file3"    : "/open/scholar/obj/icefan",
		"file9"    : "/open/mon/obj/ghost-legging",
		"amount2"  : 1,
		"amount7"  : 1,
		"amount5"  : 1,
		"amount9"  : 1,
		"file8"    : "/daemon/class/blademan/obj/shield",
		"file6"    : "/open/mogi/village/obj/mskirt",
		"file1"    : "/open/dancer/obj/maple_ribbon",
		"amount6"  : 1,
		"amount3"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"file7"    : "/daemon/class/fighter/figring",
		"amount8"  : 1,
		"file5"    : "/daemon/class/fighter/ywhand",
		"file2"    : "/open/mogi/castle/obj/lochagem",
		"amount10" : 1,
		"file4"    : "/open/dancer/obj/yuawaist",
	]) );
	set( "build", 10366 );
	set( "light_up", 1 );
	set( "owner", "miho" );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room317",
		"west"      : "/open/clan/sky-wu-chi/room/room181.c",
	]) );
	set( "long", @LONG
一走进房间里，你可以看到凤无双正在忙着清理血渍呢。旁边的电视正拨放着满清十大酷刑，在小茶几上还摆放着一些刑具，令你觉得整个人都紧张了起来。当你坐下来的时候，你注意到在桌上有一张凤无双鞭打寒雪冰霜的照片，照片里的寒雪冰霜看起来十分的舒服呢。
LONG);
	setup();
	replace_program(ROOM);
}
