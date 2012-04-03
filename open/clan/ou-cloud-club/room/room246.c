inherit ROOM;
void create() {
	set( "short", "$HIY$傲$HIC$云$NOR$居" );
	set( "object", ([
		"file8"    : "/open/snow/obj/stone",
		"amount1"  : 99999,
		"amount5"  : 1,
		"file2"    : "/open/killer/obj/bellstar",
		"file5"    : "/open/snow/obj/snow_token",
		"amount8"  : 1,
		"file9"    : "/open/killer/obj/bellstar",
		"file7"    : "/open/killer/obj/bellstar",
		"amount4"  : 99999,
		"file1"    : "/open/killer/obj/bellstar",
		"amount10" : 99999,
		"amount7"  : 99999,
		"file6"    : "/open/killer/obj/bellstar",
		"amount2"  : 99999,
		"amount6"  : 99999,
		"amount3"  : 99999,
		"file4"    : "/open/killer/obj/bellstar",
		"file3"    : "/open/killer/obj/bellstar",
		"amount9"  : 99999,
		"file10"   : "/open/killer/obj/bellstar",
	]) );
	set( "build", 17889 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room248.c",
		"south"     : "/open/clan/ou-cloud-club/room/room197.c",
		"east"      : "/open/clan/ou-cloud-club/room/room247",
		"north"     : "/open/clan/ou-cloud-club/room/room249",
	]) );
	set( "long", @LONG
这里是傲云山庄的高手们所居住的地方，傲云山庄内的
人都居住于此，拥有浓烈的肃杀味道，所以，在这里你要特
别的的小心谨慎，以免进入了不该进入的房间。

左边是小型恶人(speed)的练功房，右边则是鲸鱼(bobe)所居住了．

LONG);
	setup();
	replace_program(ROOM);
}
