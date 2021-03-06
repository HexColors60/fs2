inherit ROOM;
void create() {
	set( "short", "吉祥花园" );
	set( "owner", "roarii" );
	set( "object", ([
		"file3"    : "/open/mon/obj/ghost-claw",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/mon/obj/ghost-cloak",
		"amount2"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/mon/obj/ghost-helmet",
		"file1"    : "/open/mon/obj/ghost-claw",
		"file2"    : "/open/mon/obj/ghost-claw",
		"file6"    : "/open/mon/obj/ghost-legging",
		"file4"    : "/open/mon/obj/ghost-claw",
	]) );
	set( "build", 10833 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room4",
	]) );
	set( "long", @LONG

    这儿是黄城大道旁的吉祥花园，从这放眼过去一大片的花花草草，
平常时可以看到一些公主或是宫女在这赏花嬉戏，蝴蝶蜜蜂相互争艳，
许多闻香而来的达官贵人，不免心花怒放，看着只穿一件薄纱隐隐约约
可以看见里面只穿着小可爱的少女们，惹的远观的人心理养养的。

LONG);
	setup();
	replace_program(ROOM);
}
