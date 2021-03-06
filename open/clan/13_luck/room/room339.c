inherit ROOM;
void create() {
	set( "short", "风云道" );
	set( "object", ([
		"amount4"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/mon/obj/ghost-legging",
		"file2"    : "/open/mon/obj/ghost-helmet",
		"file10"   : "/daemon/class/blademan/obj/shield",
		"amount9"  : 1,
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"amount1"  : 1,
		"file8"    : "/daemon/class/blademan/obj/shield",
		"amount8"  : 1,
		"file6"    : "/daemon/class/bonze/puty_pullium",
		"file1"    : "/open/gblade/obj/sa-head",
		"amount10" : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"file9"    : "/daemon/class/bonze/puty_pullium",
		"file4"    : "/open/capital/obj/chen_dagger",
		"amount3"  : 1,
	]) );
	set( "owner", "smalloo" );
	set( "build", 10650 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room340",
		"south"     : "/open/clan/13_luck/room/room338",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    你急跃而起转身四望，冷月当空，[0;1;36m□[1m□[1m□[1m□[1m□[1mM[1m□[1ma[0m，[0;1;33m□[1m□[1m□[1ms[1m□[1mI[1m□[1mI[0m，花影重
重四下里山谷呜响，你继续急奔前去。再过拳柱香时分，你跨开大步
，觉得风生耳际，两[0;1;32m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[0m不住的倒退，郤地有如快马奔驰。你大
袖飘飘努力前去。此时微风徐徐吹来，天上的云层也有点儿飘忽不定
，令你觉的毛骨耸然。

LONG);
	setup();
	replace_program(ROOM);
}
