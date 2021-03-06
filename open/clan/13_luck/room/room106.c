inherit ROOM;
void create() {
	set( "short", "$HIC$绝世峰$NOR$" );
	set( "owner", "poll" );
	set( "object", ([
		"amount3"  : 29,
		"file6"    : "/open/mon/obj/ghost-helmet",
		"amount10" : 1,
		"file1"    : "/open/fire-hole/obj/r-pill",
		"amount4"  : 35,
		"file5"    : "/open/killer/obj/s_pill",
		"file4"    : "/open/ping/obj/poison_pill",
		"file8"    : "/open/mon/obj/ghost-cloak",
		"amount9"  : 13,
		"amount8"  : 1,
		"file9"    : "/open/killer/obj/black",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/fire-hole/obj/w-pill",
		"amount6"  : 1,
		"amount5"  : 466,
		"amount1"  : 14,
	]) );
	set( "build", 10137 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room60",
		"south"     : "/open/clan/13_luck/room/room105",
	]) );
	set( "long", @LONG
$HIW$风不停，人不动，一条人影在远远的方向伫立着，浓烈的杀气逼
的让你不敢靠近，忽然那人动了，手中拿着一把利刃，不停的旋转着
，舞了一招又一招，一招又快似一招，刹那间人停了，随之风也停了
，只见$HIR$绝$HIY$世$HIG$匕$HIC$首$HIW$缓缓的落在那人手中。$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
