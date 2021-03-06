inherit ROOM;
void create() {
	set( "short", "寒雪针室" );
	set( "owner", "jtl" );
	set( "object", ([
		"amount2"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/gsword/obj/dragon-sword",
		"amount8"  : 1,
		"file3"    : "/open/mon/obj/ghost-claw",
		"file8"    : "/open/tendo/obj/shoe",
		"amount6"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/marksman/obj/dragon_bow",
		"amount5"  : 1,
		"file7"    : "/open/scholar/obj/icefan",
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount3"  : 1,
		"file2"    : "/open/doctor/obj/needle9",
		"file6"    : "/open/gsword/obj/yuskirt",
	]) );
	set( "build", 11556 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room272",
	]) );
	set( "long", @LONG

    冰雪寒丝针乃是医者之师傅华佗的随身武器，光是听到华佗二字就
吓的一身冷汗，除了一身针法还有那变态的后三招式，外加狂定人的金
针渡穴令人防不胜防，只好跟他速战速决，身上又带有人灵丹，所以你
经验值不多，可别拿自己生命开玩笑。

LONG);
	setup();
	replace_program(ROOM);
}
