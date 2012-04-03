inherit ROOM;
void create() {
	set( "short", "雾之林" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room169",
		"east"      : "/open/clan/13_luck/room/room166.c",
		"west"      : "/open/clan/13_luck/room/room168.c",
		"north"     : "/open/clan/13_luck/room/room169",
	]) );
	set( "long", @LONG

　　谜样般的森林，终年浓雾不散，眼前只见白茫茫的一大片，伸手
不见五指。越往里头走去，雾气更是浓厚，西方似乎有一个阴暗、矮
小的洞穴，里面传出稀稀嗦嗦的声音，似乎有一些生物在里面走动的
样子，但听不出是啥东西。

LONG);
	setup();
	replace_program(ROOM);
}
