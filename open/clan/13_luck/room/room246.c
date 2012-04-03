inherit ROOM;
void create() {
	set( "short", "齐家安帮楼" );
	set( "owner", "adeyzit" );
	set( "build", 10269 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room180",
		"up"        : "/open/clan/13_luck/room/room245",
	]) );
	set( "long", @LONG

    [0;1;5;33m□[1;5mQ[1;5m□[1;5mT[1;5m□[1;5mN[1;5m□[1;5m□[0m成立至今，帮务蒸蒸日上，也有赖几位前人的努力帮住
帮派稳固，如天，残心，廖官人，混口饭吃，可爱小猪头等人，为帮
牺牲奉献，为了感谢这些前人的努力，就把此楼命名为齐家安帮楼，
希望后人能跟他们学习并有过之而无不及。

LONG);
	setup();
	replace_program(ROOM);
}
