inherit ROOM;
void create() {
	set( "short", "青龙舞天" );
	set( "owner", "mad" );
	set( "object", ([
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"file4"    : "/daemon/class/blademan/obj/ublade",
		"amount5"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"file10"   : "/open/wu/npc/obj/armband",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount10" : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
	]) );
	set( "build", 15238 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room20.c",
		"up"        : "/open/clan/13_luck/room/room22",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    在爬了一段时间，终于看到了终点就在不远处，你兴奋的不管四周
的美景，二话不说的向前直冲，一步当两步的跑着，四周全布满了白云
，整个人就好像漂浮在空中，心中有说不出的快乐，期待的一看十三吉
祥的行政中枢。

LONG);
	setup();
	replace_program(ROOM);
}
