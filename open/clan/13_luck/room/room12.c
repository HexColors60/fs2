inherit ROOM;
void create() {
	set( "short", "白虎堂口" );
	set( "owner", "compaq" );
	set( "object", ([
		"amount4"  : 1,
		"file2"    : "/open/scholar/obj/icefan",
		"amount6"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"file4"    : "/daemon/class/blademan/obj/shield",
		"amount10" : 1,
		"amount3"  : 1,
		"file10"   : "/open/ping/obj/chilin_legging",
		"file3"    : "/open/dancer/obj/yuawaist",
		"amount9"  : 1,
		"file9"    : "/open/prayer/obj/boris-boots",
		"file6"    : "/open/mogi/mountain/obj/frog-pill",
	]) );
	set( "build", 10248 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room13.c",
		"enter"     : "/open/clan/13_luck/room/room17",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    走到了都是喧哗声的地方，看看四周挤满了人，往上看到白虎堂三
个大字，你问了一下周围的人，原来他们都是来申请当十三吉祥士兵的
，有的是这里的老百姓有的是远从他地来到这里的，看着每个人都说着
十三吉祥的过去种种事迹，可见十三吉祥是声名远播的。

LONG);
	setup();
	replace_program(ROOM);
}
