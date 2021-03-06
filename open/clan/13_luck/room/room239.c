inherit ROOM;
void create() {
	set( "short", "禁地-神兵室" );
	set( "object", ([
		"amount2"  : 45,
		"amount10" : 1,
		"file8"    : "/open/capital/guard/gring",
		"file9"    : "/open/capital/guard/gring",
		"file2"    : "/open/ping/obj/poison_pill",
		"amount4"  : 8,
		"amount8"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount6"  : 1,
		"file5"    : "/open/magic-manor/obj/hwa-je-icer",
		"file4"    : "/open/mogi/castle/obj/blood-water",
		"file3"    : "/open/fire-hole/obj/p-pill",
		"amount3"  : 47,
		"file10"   : "/open/capital/guard/gring",
		"amount9"  : 1,
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 55,
		"amount5"  : 1,
		"file7"    : "/open/magic-manor/obj/fire-color-ribbon",
	]) );
	set( "owner", "dancer" );
	set( "build", 10299 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room238",
	]) );
	set( "long", @LONG

历代宫主都会打隐居在止的江湖人士的配兵做一番评鉴,如果是稀世的神
兵就会将止神兵收藏在这里,以免后人遇到重大危机时无神兵利器可以抗
敌,止时你一眼望看到排在兵架上的首三把神兵分别是自远古时代三界勇
者所遗留下来的配兵,天勇者龙龙(THIEF)-终神秘器 地勇者厉若海(TKC)-
圣刀无刃 水勇者苏菲亚(SUFAYA)-魔神器 幻空,原来皆是收藏在止.

LONG);
	setup();
	replace_program(ROOM);
}
