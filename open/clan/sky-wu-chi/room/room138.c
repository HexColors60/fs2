inherit ROOM;
void create() {
	set( "short", "$HIW$命运之室$NOR$" );
	set( "owner", "atropos" );
	set( "object", ([
		"amount2"  : 1,
		"file4"    : "/open/ping/obj/poison_pill",
		"amount8"  : 1,
		"file5"    : "/open/ping/obj/chilin_legging",
		"file3"    : "/open/ping/obj/gold_hand",
		"file1"    : "/open/scholar/obj/icefan",
		"amount9"  : 100,
		"amount3"  : 1,
		"amount7"  : 1,
		"amount4"  : 10,
		"file6"    : "/open/dancer/obj/yuawaist",
		"file9"    : "/open/doctor/pill/sky_pill",
		"file8"    : "/open/love/obj/shield",
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"file2"    : "/daemon/class/bonze/puty_pullium",
		"amount10" : 1,
		"amount1"  : 1,
		"file10"   : "/obj/gift/bingtang",
		"amount6"  : 1,
		"amount5"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10056 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room21.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
{命运之线重我手中流出,
每个人都被它掌握,
我知道它如何掌握,
我清楚它将流向何方,
我清楚它的强韧,
但我终究只能静静看着它......}
口中低喃着小玻正不断的织出命运之丝...
因为她就是命运三女神之首  $HIC$阿特洛玻丝$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
