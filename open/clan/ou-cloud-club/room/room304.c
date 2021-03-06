inherit ROOM;
void create() {
	set( "short", "$HIR$爱情$NOR$" );
	set( "object", ([
		"amount4"  : 24,
		"amount7"  : 22,
		"amount1"  : 20,
		"file6"    : "/open/port/obj/wolf_ring",
		"amount6"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/dancer/obj/maple_ribbon",
		"file5"    : "/open/mon/obj/ghost-claw",
		"file4"    : "/open/doctor/pill/ff_pill",
		"amount2"  : 1,
		"file9"    : "/open/common/obj/pill1",
		"file1"    : "/open/doctor/pill/ice_pill",
		"amount9"  : 61,
		"file7"    : "/open/doctor/pill/f_pill",
	]) );
	set( "owner", "bleak" );
	set( "build", 10078 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room302",
	]) );
	set( "long", @LONG
世上若只有一件事能洗去人们的憔悴，那就是情人的泪。
人生的初恋只有一次，就正如死亡也只有一次一样。
原来能为自己所爱的人吃苦，竟也是一种快乐，
只是世上有几人能享受到这种快乐。
人为什么总是对自己已得到的情感不加以珍惜，却在失去后
再追悔呢？
而这种痛苦，本来就是人类最古老，最深邃的痛苦。
爱情不是占有的，而是供给与牺牲的。
LONG);
	setup();
	replace_program(ROOM);
}
