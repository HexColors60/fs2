inherit ROOM;
void create() {
	set( "short", "普通房间" );
	set( "object", ([
		"file4"    : "/daemon/class/fighter/armband",
		"amount4"  : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
		"file7"    : "/open/ping/obj/gold_hand",
		"amount2"  : 1,
		"file8"    : "/open/mon/obj/ghost-helmet",
		"amount3"  : 1,
		"file6"    : "/open/prayer/obj/boris-cloth",
		"file1"    : "/open/mon/obj/ghost-legging",
		"amount7"  : 1,
		"amount1"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/mon/obj/ghost-claw",
		"amount5"  : 1,
		"amount8"  : 1,
		"file2"    : "/open/scholar/obj/icefan",
	]) );
	set( "owner", "hild" );
	set( "build", 10008 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room179",
	]) );
	set( "long", @LONG
这房间跟是一间很普通的房间，向南看，看到有不少的刀，向东看
看到落雷，听到恐怖的降雷声，向西看，看到有许多的雕像，有白虎、
朱雀、玄武，这四大圣兽的排列位置让人觉得有一种，是阵式的排列法
看来想要进去得要有强大的轻功能力，以及过人的智慧，才能安然度过
这间房间看来平凡，其实才是最不平凡的房间。原因如何下回分解。


LONG);
	setup();
	replace_program(ROOM);
}
