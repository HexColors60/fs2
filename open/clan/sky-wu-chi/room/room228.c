inherit ROOM;
void create() {
	set( "short", "小白菜的缎带房" );
	set( "object", ([
		"amount7"  : 1,
		"file7"    : "/open/killer/weapon/k_torch",
		"file3"    : "/open/mogi/castle/obj/sspill",
		"amount6"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/gsword/obj/ring-1",
		"file6"    : "/open/port/obj/wolf_ring",
		"amount2"  : 1,
		"amount4"  : 1,
		"amount5"  : 1,
		"file8"    : "/open/capital/room/king/obj/dagger1",
		"file5"    : "/open/gsword/obj/ring-1",
		"file2"    : "/open/love/obj/cloth1",
		"amount3"  : 2,
		"amount8"  : 1,
		"file1"    : "/open/gsword/obj/yuskirt",
	]) );
	set( "owner", "sski" );
	set( "build", 10116 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room227",
		"east"      : "/open/clan/sky-wu-chi/room/room123.c",
	]) );
	set( "long", @LONG
顾明思议,这里就是小白菜的放置武器的地方了,而这里都放些
什么东西呢,你可以四处来看看,但我八成看你一定想不通这里怎
么全都是一些缎带呢,而这些缎带为啥会是小白菜的武器呢..你
就不禁的拿起了其中一个缎带来看,哇赛,不看还好,看了之后你
直呼这真的是好兵器ㄚ..原来这个缎带就叫做枫之舞(Maple ribbon)

LONG);
	setup();
	replace_program(ROOM);
}
