inherit ROOM;
void create() {
	set( "short", "$HIG$杀意魔戒$NOR$存放区" );
	set( "object", ([
		"amount10" : 1,
		"file8"    : "/open/killer/obj/k_ring",
		"file10"   : "/open/killer/obj/k_ring",
		"amount1"  : 1,
		"file3"    : "/open/killer/obj/k_ring",
		"amount8"  : 1,
		"file4"    : "/open/killer/obj/k_ring",
		"file7"    : "/open/killer/obj/k_ring",
		"amount2"  : 1,
		"file9"    : "/open/killer/obj/k_ring",
		"file2"    : "/open/killer/obj/k_ring",
		"file6"    : "/open/killer/obj/k_ring",
		"amount7"  : 1,
		"file1"    : "/open/killer/obj/k_ring",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"amount9"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/killer/obj/k_ring",
	]) );
	set( "build", 10467 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room39",
	]) );
	set( "long", @LONG
杀意魔戒是相传产于天山派禁地的矿石所炼出的魔水晶所制成,平时是黑牙联的杀手
赖以成名的杀敌利器,一般人想要得到除了挑战黑牙联主席外别无他法,还要冒着被追杀
的危险,小敏帮主特地任命帮中的杀手收集一些戒指,收藏在这里以为备用

LONG);
	setup();
	replace_program(ROOM);
}
