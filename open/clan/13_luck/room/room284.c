inherit ROOM;
void create() {
	set( "short", "EMC营区停车场" );
	set( "object", ([
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
		"file2"    : "/obj/gift/hobowdan",
		"amount4"  : 1,
		"file3"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount2"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/mon/obj/ghost-claw",
		"amount9"  : 1,
		"amount6"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/gblade/obj/sa-head",
		"file1"    : "/open/mon/obj/ghost-cloak",
		"amount8"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
	]) );
	set( "owner", "adeyzit" );
	set( "build", 10605 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room111",
		"north"     : "/open/clan/13_luck/room/room289",
		"east"      : "/open/clan/13_luck/room/room292.c",
		"south"     : "/open/clan/13_luck/room/room290.c",
		"west"      : "/open/clan/13_luck/room/room291.c",
	]) );
	set( "long", @LONG
停车场..放着很多车车..军用大卡..悍马车..跟得力卡..及炮车
悍马可以跑荒郊野外的山地..马力够强..上面还可以架四零榴弹枪与
一些炮..而炮车可以装大一点的炮..得力卡为用车..加上指挥车..大
卡可以运兵..采买..但只能走大马路..
LONG);
	setup();
	replace_program(ROOM);
}
