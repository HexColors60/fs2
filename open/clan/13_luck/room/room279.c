inherit ROOM;
void create() {
	set( "short", "寒冰房" );
	set( "owner", "suzukiami" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room270",
	]) );
	set( "object", ([
		"amount5"  : 1,
		"amount6"  : 1,
		"file5"    : "/open/gsword/obj/dragon-sword",
		"amount4"  : 1,
		"amount7"  : 23,
		"amount8"  : 3,
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"amount3"  : 1,
		"file6"    : "/open/mogi/village/obj/mogi_ring",
		"file3"    : "/open/ping/obj/gold_hand",
		"file4"    : "/open/doctor/obj/needle9",
		"file7"    : "/open/ping/obj/poison_pill",
	]) );
	set( "build", 10272 );
	set( "light_up", 1 );
	set( "long", @LONG

    寒冰，乃是千年冰雪所成，所以都不会溶化，而此物又为风行山寨
的寨主夫人所有，美貌惊为天人，但是有秀丽的外表，也有高强的武功
，让多少想跟他三个女的人，惨死在他的手中，身上有着段家他讨厌的
定人绝技，让人防不胜防。

LONG);
	setup();
	replace_program(ROOM);
}
