inherit ROOM;
void create() {
	set( "short", "菩提袈裟房" );
	set( "object", ([
		"file1"    : "/open/marksman/obj/dragon_bow",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/ping/obj/ring-2",
		"amount4"  : 1,
		"file4"    : "/daemon/class/bonze/puty_pullium",
		"file2"    : "/open/scholar/obj/icefan",
	]) );
	set( "owner", "suzukiami" );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room279",
		"south"     : "/open/clan/13_luck/room/room299.c",
	]) );
	set( "build", 10068 );
	set( "light_up", 1 );
	set( "long", @LONG

    菩提本无树，明镜亦非台，本来无一物，何处惹尘埃，传说中的防
具，菩萨袈裟，在天下武功出少林的，少林掌门人手上，还有必免杀气
过高而档在路口的空闻，是个好防具，也是少林开放的一天，就是菩提
袈裟缺货的一天。

LONG);
	setup();
	replace_program(ROOM);
}
