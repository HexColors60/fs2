inherit ROOM;
void create() {
	set( "short", "隔世桥" );
	set( "owner", "dancer" );
	set( "object", ([
		"amount10" : 1,
		"amount3"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
		"amount7"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"file7"    : "/open/firedancer/npc/eq/r_boots",
		"file4"    : "/open/mogi/castle/obj/lochagem",
		"amount1"  : 1,
		"file10"   : "/daemon/class/fighter/figring",
		"amount4"  : 1,
		"amount8"  : 1,
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file1"    : "/open/tendo/obj/chaosbelt",
		"file6"    : "/open/firedancer/npc/eq/r_hands",
		"file9"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount6"  : 1,
		"file8"    : "/open/firedancer/npc/eq/r_pants",
		"amount5"  : 1,
	]) );
	set( "build", 10011 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room94",
		"enter"     : "/open/clan/13_luck/room/room119",
	]) );
	set( "long", @LONG
你漫步欣赏着这湖美丽的风光美景,发现在不远处有一条连接至
湖中小岛的桥,止时的你急着前往小岛去一探究竟是否为一个隐
居的好地方,正当你靠近桥时发现桥口有一块大石,石上写着 不欢
迎外来客的拜访,只欢迎要来止安度晚年的人,看到止你心中一慌
不知是否要就只隐居去.
LONG);
	setup();
	replace_program(ROOM);
}
