inherit ROOM;
void create() {
	set( "short", "$HIM$御书房$NOR$" );
	set( "owner", "enter" );
	set( "object", ([
		"amount4"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file5"    : "/open/capital/guard/gring",
		"file2"    : "/open/capital/obj/gold_pill",
		"file10"   : "/open/killer/headkill/obj/world_dag",
		"file7"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"amount1"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/ping/questsfan/obj/diamond_armor",
		"file6"    : "/open/doctor/obj/d-mark",
		"file1"    : "/open/ping/questsfan/obj/diamond_cloak",
		"amount10" : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/killer/headkill/obj/world_dag",
	]) );
	set( "light_up", 1 );
	set( "build", 10149 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room13.c",
		"north"     : "/open/clan/ou-cloud-club/room/room144.c",
	]) );
	set( "long", @LONG
帮主的御书房，墙上挂着另一幅上千张的狗
狗拼图，右边墙角摆着各式各样的书架放置帮主
的武学心得及秘笈，中间摆着许多的木人桩跟铜
人以供帮主在此房练武之用，只见地上则躺着许
多的坏掉的木铜人，据说帮主一天可打坏上百的
木人桩及铜人像．

LONG);
	setup();
	replace_program(ROOM);
}
