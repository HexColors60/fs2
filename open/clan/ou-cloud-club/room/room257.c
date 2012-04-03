inherit ROOM;
void create() {
	set( "short", "$HIM$粉笔$HIW$之$HIG$家$NOR$" );
	set( "owner", "speed" );
	set( "object", ([
		"file6"    : "/open/port/obj/wolf_ring",
		"file3"    : "/open/ping/obj/poison_pill",
		"file9"    : "/open/gsword/obj/yuskirt",
		"file5"    : "/open/gblade/obj/sa-head",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"file10"   : "/open/ping/obj/cloud",
		"amount4"  : 1,
		"amount10" : 1,
		"file8"    : "/open/scholar/obj/s_hands",
		"amount7"  : 1,
		"amount3"  : 8,
		"file1"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file7"    : "/open/gsword/obj/ring-1",
		"amount5"  : 1,
		"file4"    : "/open/ping/obj/neck0",
		"amount1"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10025 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room248",
	]) );
	set( "long", @LONG
粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家
粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家
粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家
粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家
粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家
粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家
粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家
粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家
粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家粉笔的家
LONG);
	setup();
	replace_program(ROOM);
}
