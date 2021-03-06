inherit ROOM;
void create() {
	set( "short", "妖幻护膝房" );
	set( "object", ([
		"amount10" : 1,
		"amount9"  : 1,
		"file1"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount5"  : 1,
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"amount7"  : 1,
		"file3"    : "/open/dancer/obj/yuawaist",
		"amount4"  : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount3"  : 1,
		"file10"   : "/open/mon/obj/ghost-helmet",
		"amount8"  : 1,
		"file4"    : "/open/scholar/obj/icefan",
		"amount2"  : 1,
		"file2"    : "/open/ping/obj/gold_hand",
		"amount1"  : 1,
		"file9"    : "/open/gsword/obj/yuskirt",
		"file8"    : "/open/mon/obj/ghost-cloak",
		"file6"    : "/open/mogi/castle/obj/lochagem",
		"amount6"  : 1,
	]) );
	set( "owner", "mei" );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room308",
		"south"     : "/open/clan/13_luck/room/room303.c",
	]) );
	set( "build", 10245 );
	set( "light_up", 1 );
	set( "long", @LONG

    此防具，为闻名无不吓破胆的千年树妖舞风扬身上所有的，此妖有
千年之功力，长年在长白山上修练，法术更是无人能敌，与他为敌只会
一肚子大便的状态，尤其是虚弱，所以他的防具不是说有就有的，也要
看有没有人敢去打为了那一件[0;1;33m□[1m□[1m□[1m□[1m□[1m@[1m□[1m□[0m。

LONG);
	setup();
	replace_program(ROOM);
}
