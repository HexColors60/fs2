inherit ROOM;
void create() {
	set( "short", "冷-磬-玉-蝶-居." );
	set( "owner", "palapala" );
	set( "light_up", 1 );
	set( "build", 10361 );
	set( "object", ([
		"amount9"  : 1,
		"file7"    : "/open/ping/questsfan/obj/diamond_armor",
		"file6"    : "/open/ping/questsfan/obj/diamond_skirt",
		"amount5"  : 1,
		"amount10" : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/ping/questsfan/obj/diamond_hands",
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"amount8"  : 1,
		"file8"    : "/open/dancer/obj/yuaboots",
		"file2"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file5"    : "/open/ping/questsfan/obj/diamond_cloak",
		"amount7"  : 1,
		"file9"    : "/open/dancer/obj/yuawaist",
		"file1"    : "/daemon/class/fighter/ywhelme",
		"amount1"  : 1,
		"amount2"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/ping/questsfan/obj/diamond_hairpin",
	]) );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room145",
	]) );
	set( "long", @LONG
你走进了一间有如书院一样的房子里面，你发现这个建筑非常的优雅
地上的白玉大理石砖，与两旁的花圃盛开的水仙花互相的照映着仿佛是
在说明这房子的主人是个非常懂的生活的人，青翠翠的草皮上有着一
点一点的露上在那小草的叶梢上，你感觉到走进来时有种让人心旷神
怡的感觉，你越来越想认识这样房子的主人到底是谁

LONG);
	setup();
	replace_program(ROOM);
}
