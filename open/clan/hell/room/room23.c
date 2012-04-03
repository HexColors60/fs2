inherit ROOM;
void create() {
	set( "short", "$RED$‘阎罗王’$NOR$的$HIY$收藏地狱$NOR$‘$HIC$千坟之水$NOR$’" );
	set( "object", ([
		"amount1"  : 8,
		"file1"    : "/open/mogi/castle/obj/blood-water",
	]) );
	set( "light_up", 1 );
	set( "build", 10286 );
	set( "exits", ([
		"south"     : "/open/clan/hell/room/room30.c",
		"west"      : "/open/clan/hell/room/room27.c",
		"SH"        : "/open/clan/hell/room/room92",
		"up"        : "/open/clan/hell/room/room132",
		"east"      : "/open/clan/hell/room/room22.c",
		"down"      : "/open/clan/hell/room/hall.c",
		"north"     : "/open/clan/hell/room/room28.c",
		"FH"        : "/open/clan/hell/room/room91.c",
	]) );
	set( "long", @LONG
这里是地府的阎罗王收藏东西的地方,他的鬼子鬼孙们从四处蒐集回来的东西
都会收藏在这里,由于收藏品实在太多了,所以他收藏的区域不只一间,这里往四
周延神出去,各有收藏诸般兵器的地方,当然也还有各种神丹妙药,只要是受到阎
罗王认可的人都可以任意取用,

LONG);
	setup();
	replace_program(ROOM);
}
