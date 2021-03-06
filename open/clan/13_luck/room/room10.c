inherit ROOM;
void create() {
	set( "short", "青龙殿" );
	set( "object", ([
		"amount4"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"amount3"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10236 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room18",
		"east"      : "/open/clan/13_luck/room/room16.c",
		"out"       : "/open/clan/13_luck/room/room11.c",
		"west"      : "/open/clan/13_luck/room/room13.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    一进青龙殿踏在青色的地毯上，有一种非凡的气势，好比自己是九
五之尊，能够左右别人，在左右的墙上都画着青龙，青龙各自争的自己
的天空，更能称托出十三吉祥雄霸天下的决心，往西可以到白虎堂，往
东可以到朱雀堂。

LONG);
	setup();
	replace_program(ROOM);
}
