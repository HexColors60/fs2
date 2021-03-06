inherit ROOM;
void create() {
	set( "short", "龙之穴" );
	set( "owner", "fighter" );
	set( "object", ([
		"file8"    : "/obj/gift/xisuidan",
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount7"  : 1,
		"amount9"  : 1,
		"file7"    : "/obj/gift/xisuidan",
		"file9"    : "/obj/gift/hobowdan",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/obj/gift/hobowdan",
		"amount1"  : 1,
		"file1"    : "/obj/gift/hobowdan",
		"amount6"  : 1,
		"amount2"  : 1,
		"file2"    : "/obj/gift/xiandan",
		"amount3"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/gblade/obj/dragon_book",
		"amount10" : 1,
	]) );
	set( "build", 10194 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room348",
		"out"       : "/open/clan/13_luck/room/room265.c",
		"south"     : "/open/clan/13_luck/room/room324.c",
	]) );
	set( "long", @LONG

    简单的石床，几张石椅石桌，上面几本的武功书籍散乱放置，整
天沈浸于武学的究极境界。旁边就放着一些主人所爱穿的衣服防具，
旁边还有几只奇异的小动物在嘻戏玩耍着，长着小翅膀，不时飞旋于
空中，口中偶而还会吐着小小的火焰，会不会是武林中的传言神兽─
[0;1;32m□[1mt[1m□[1m~[0m．[0;1;31m□[1mW[0m


LONG);
	setup();
	replace_program(ROOM);
}
