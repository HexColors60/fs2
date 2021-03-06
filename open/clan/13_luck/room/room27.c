inherit ROOM;
void create() {
	set( "short", "秋阳流" );
	set( "owner", "amdmp" );
	set( "object", ([
		"file2"    : "/open/fire-hole/obj/r-pill",
		"file1"    : "/open/fire-hole/obj/b-pill",
		"file4"    : "/daemon/class/blademan/obj/skykey",
		"file3"    : "/open/ping/obj/poison_pill",
		"amount1"  : 209,
		"amount6"  : 234,
		"amount4"  : 1,
		"file6"    : "/open/fire-hole/obj/y-pill",
		"amount3"  : 33,
		"amount2"  : 83,
	]) );
	set( "build", 10009 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room28",
		"east"      : "/open/clan/13_luck/room/room26.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    你已经到了吉祥水道的正中央了，你看看四周觉得绿意盎然水道边
有不少的小孩在嘻戏着，令你想起自己小时的种种，历历在目，当你一
回神发现四周的景象慢慢变了，绿叶稍稍转红宛如入秋，你稍微拉拉衣
服，你觉得天气有点转凉了，这里是十三吉祥著名的秋阳流只要过了这
，秋天气息就非常浓了。

LONG);
	setup();
	replace_program(ROOM);
}
