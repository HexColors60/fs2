inherit ROOM;
void create() {
	set( "short", "八歧小蛇滴窝" );
	set( "object", ([
		"amount3"  : 1,
		"amount9"  : 1,
		"file3"    : "/open/scholar/obj/icefan",
		"amount8"  : 1,
		"file4"    : "/open/ping/obj/gold_hand",
		"file8"    : "/open/wu/npc/obj/armband",
		"file2"    : "/open/ping/obj/ring-2",
		"file1"    : "/open/ping/obj/chilin_legging",
		"amount7"  : 1,
		"amount10" : 1,
		"file10"   : "/open/gsword/obj/nine_hat",
		"amount1"  : 1,
		"file5"    : "/open/gsword/obj/yugem",
		"amount6"  : 1,
		"file6"    : "/daemon/class/blademan/obj/shield",
		"amount2"  : 1,
		"amount5"  : 1,
		"amount4"  : 1,
		"file7"    : "/daemon/class/bonze/puty_pullium",
		"file9"    : "/open/gsword/obj/yuskirt",
	]) );
	set( "owner", "pitlin" );
	set( "build", 10047 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room76",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
这是一个小蛇休息的好地方，有一股芳香滴味道，使人清新通畅
让人有一种快睡着滴感觉，在入睡时让你昏昏欲睡，任别人也无法吵
醒你。旁边有个小床，衣橱，冰箱，电视，冷气，进入后有一种舍不
得离开低感觉，但始终这不是你滴房间，请你速速离开，以免打扰小
蛇安息。ps.(安息=安静休息)
LONG);
	setup();
	replace_program(ROOM);
}
