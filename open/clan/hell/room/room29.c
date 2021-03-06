inherit ROOM;
void create() {
	set( "short", "$HBCYN$天晶结界$NOR$" );
	set( "owner", "neun" );
	set( "object", ([
		"file5"    : "/open/killer/headkill/obj/w_dag",
		"amount4"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/killer/headkill/obj/i_dag",
		"file1"    : "/open/killer/obj/dagger",
		"amount7"  : 1,
		"amount2"  : 260,
		"file4"    : "/open/killer/headkill/obj/f_dag",
		"amount5"  : 1,
		"file6"    : "/open/killer/headkill/obj/e_dag",
		"amount1"  : 1,
		"file2"    : "/open/killer/obj/s_pill",
		"amount6"  : 1,
		"file7"    : "/open/magic-manor/obj/magic-sign",
	]) );
	set( "light_up", 1 );
	set( "build", 10076 );
	set( "exits", ([
		"enter"     : "/open/clan/hell/room/room76",
		"west"      : "/open/clan/hell/room/room35.c",
		"out"       : "/open/clan/hell/room/room30.c",
		"east"      : "/open/clan/hell/room/room36.c",
	]) );
	set( "long", @LONG
传说中书生最好的装备,虹晶装备全套,虽然是针对书生设计的,但其实对于其他
门派来说,其实也是不错的防身装备.所以帮主平时特别准备三套此种装备,置于此结
界中,让帮众在偷懒或是紧急的时候可以来此拿取,结界的顶端刻着帮主的叮咛,希望
帮众使用完后都能自动归还

LONG);
	setup();
	replace_program(ROOM);
}
