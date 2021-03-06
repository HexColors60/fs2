inherit ROOM;
void create() {
	set( "short", "小猪头的大厅" );
	set( "owner", "pighead" );
	set( "object", ([
		"amount6"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/fire-hole/obj/w-pill",
		"amount3"  : 20,
		"amount4"  : 1,
		"file10"   : "/open/killer/headkill/obj/world_dag",
		"file1"    : "/open/fire-hole/obj/b-pill",
		"amount10" : 1,
		"file2"    : "/open/fire-hole/obj/p-pill",
		"file9"    : "/open/mon/obj/ghost-cloak",
		"amount1"  : 13,
		"file5"    : "/open/fire-hole/obj/g-pill",
		"amount2"  : 7,
		"file7"    : "/open/killer/obj/k_ring",
		"file3"    : "/open/fire-hole/obj/k-pill",
		"file6"    : "/open/mon/obj/ghost-helmet",
		"amount7"  : 1,
		"file8"    : "/open/mon/obj/ghost-helmet",
		"amount9"  : 1,
		"amount5"  : 48,
	]) );
	set( "light_up", 1 );
	set( "build", 10467 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room93.c",
		"north"     : "/open/clan/13_luck/room/room296.c",
		"south"     : "/open/clan/13_luck/room/room293",
		"east"      : "/open/clan/13_luck/room/room295.c",
		"west"      : "/open/clan/13_luck/room/room294.c",
	]) );
	set( "long", @LONG

    这里是可爱小猪头的大厅，以这边为中心，分别有东西南北厢房
往东边是东箱房，主要是储存一般的防具，为平常战斗之用，往西边
是西厢房，主要是储存一般的武器，为平常战斗之用，往北边是北厢
房，主要是储存各式各样的药品，往南边是南厢房，主要是储存一些
杂七杂八的物品。


LONG);
	setup();
	replace_program(ROOM);
}
