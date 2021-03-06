inherit ROOM;
void create() {
	set( "short", "天雷" );
	set( "owner", "hild" );
	set( "object", ([
		"amount6"  : 82,
		"amount5"  : 49,
		"file1"    : "/open/ping/obj/poison_pill",
		"file8"    : "/open/doctor/pill/gnd_pill",
		"amount8"  : 8,
		"file6"    : "/open/fire-hole/obj/w-pill",
		"amount9"  : 1,
		"file3"    : "/open/fire-hole/obj/r-pill",
		"amount4"  : 12,
		"file5"    : "/open/fire-hole/obj/p-pill",
		"file9"    : "/obj/gift/xisuidan",
		"amount1"  : 53,
		"file7"    : "/open/doctor/pill/sky_pill",
		"amount7"  : 14,
		"amount3"  : 88,
		"file2"    : "/open/doctor/pill/gnd_pill",
		"file4"    : "/open/fire-hole/obj/b-pill",
		"amount2"  : 75,
	]) );
	set( "build", 10004 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room168.c",
	]) );
	set( "long", @LONG
这房间充满了五行八卦的排列法，仔细一看中间有个天雷雷石，是引发
阵行的关键，一想要走进去，忽然天雷勾动地火一发不可收拾，想要进
入这房间，除了要对易经八卦要有相当的了解，还要有抗幻的能力，要
不然一发动阵行，没有人可以逃出这地方。就算平安无事，幻觉就会出
来。抗不了只有在这死的份。

LONG);
	setup();
	replace_program(ROOM);
}
