inherit ROOM;
void create() {
	set( "short", "皮皮的家" );
	set( "object", ([
		"amount3"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/mon/obj/ghost-cloak",
		"file1"    : "/open/wind-rain/obj/sun_red_cloth",
		"file7"    : "/open/ping/obj/ring-2",
		"amount4"  : 1,
		"amount1"  : 1,
		"amount6"  : 1,
		"file8"    : "/open/ping/obj/gold_hand",
		"file3"    : "/daemon/class/blademan/obj/shield",
		"file6"    : "/open/mogi/village/obj/mogi_ring",
		"file4"    : "/open/ping/obj/iceger",
		"amount8"  : 1,
		"amount2"  : 1,
	]) );
	set( "owner", "kris" );
	set( "build", 9231 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room92",
	]) );
	set( "long", @LONG
这里就是我是皮皮是我的家，房间的摆设十分的简单，几张竹制
的椅子，配上一张竹子制成的方桌，桌上则摆着一盆小盆栽，除
此之外就空荡荡的，可谓家徒四璧，想必此处的主人一定没什么
搞头。  从这儿往东走可以回到绿茶园的前庭。
LONG);
	setup();
	replace_program(ROOM);
}
