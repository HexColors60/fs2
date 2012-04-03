inherit ROOM;
void create() {
	set( "short", "雾之林" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room158",
		"east"      : "/open/clan/13_luck/room/room157.c",
		"west"      : "/open/clan/13_luck/room/room163.c",
		"north"     : "/open/clan/13_luck/room/room158.c",
	]) );
	set( "long", @LONG

　　谜样般的森林，终年浓雾不散，眼前只见白茫茫的一大片，伸手
不见五指。远处飘来一阵阵的恶臭，四周一片死寂，了无生气。越往
里面走去，心里的那种不安全感越来越浓，而接踵而来的压迫感，让
人有种往回走的冲动。

LONG);
	setup();
	replace_program(ROOM);
}
