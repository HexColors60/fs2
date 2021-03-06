inherit ROOM;
void create() {
	set( "short", "醉仙亭" );
	set( "owner", "mad" );
	set( "object", ([
		"amount4"  : 1,
		"file10"   : "/obj/poison/dark_poison",
		"file9"    : "/open/main/obj/et_sword",
		"amount6"  : 429,
		"amount2"  : 1,
		"file1"    : "/open/doctor/obj/feather",
		"amount1"  : 1,
		"amount8"  : 812,
		"amount9"  : 1,
		"amount7"  : 682,
		"file4"    : "/open/doctor/obj/feather",
		"amount5"  : 235,
		"amount10" : 100,
		"file3"    : "/open/doctor/obj/d-mark",
		"file6"    : "/obj/poison/rose_poison",
		"file8"    : "/obj/poison/dark_poison",
		"file7"    : "/obj/poison/five_poison",
		"file5"    : "/obj/poison/rose_poison",
		"amount3"  : 1,
		"file2"    : "/open/doctor/obj/feather",
	]) );
	set( "build", 11094 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room62",
	]) );
	set( "long", @LONG

    来到这里，四周种满无数奇花异卉，一座由青龙盘天，玄武守护
的五角凉亭置立于此，仔细一看，亭中圆桌于中，白虎形状的无数石
倚随意置于亭内，石质皆由大理陶瓷铸造而成，四大石柱上分别刻上
朱雀腾空之飞舞美姿，亭旁小河孱孱，游鱼细数，岸边草木相映，鹤
立其中，四周景观如画，令你不禁想坐在亭中细观这无数美景。

LONG);
	setup();
	replace_program(ROOM);
}
