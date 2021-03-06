inherit ROOM;
void create() {
	set( "short", "飘云扇室" );
	set( "owner", "sznking" );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/open/port/obj/wolf_ring",
		"amount8"  : 1,
		"amount9"  : 1,
		"file3"    : "/open/gsword/obj/dragon-sword",
		"amount6"  : 1,
		"file7"    : "/open/scholar/obj/icefan",
		"amount7"  : 1,
		"file8"    : "/open/ping/obj/gold_hand",
		"file4"    : "/open/mogi/dragon/obj/key",
		"amount5"  : 1,
		"file6"    : "/open/tendo/obj/chaosbelt",
		"amount10" : 1,
		"file1"    : "/open/mon/obj/ghost-claw",
		"amount4"  : 1,
		"file10"   : "/open/gsword/obj/yuskirt",
		"file9"    : "/open/mogi/castle/obj/lochagem",
		"amount3"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/tendo/obj/shoe",
	]) );
	set( "light_up", 1 );
	set( "build", 10035 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room275",
	]) );
	set( "long", @LONG

    飘云扇，段家的老大随身之物，为段家之人使用有着火凤凰之术，
段家以点穴出名，被点到无不看着自己被眼睁睁的被打死就是被火凤凰
烧死，所以段家攻击虽低，但是被定走了也会挂，小心段家的敌人，可
别轻易跟他们结仇。

LONG);
	setup();
	replace_program(ROOM);
}
