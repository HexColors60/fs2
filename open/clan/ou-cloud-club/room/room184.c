inherit ROOM;
void create() {
	set( "short", "$HIC$傲$HIW$云$NOR$阁" );
	set( "light_up", 1 );
	set( "build", 10032 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room183.c",
		"north"     : "/open/clan/ou-cloud-club/room/room193",
		"east"      : "/open/clan/ou-cloud-club/room/room192.c",
		"south"     : "/open/clan/ou-cloud-club/room/room181.c",
	]) );
	set( "long", @LONG
这里是傲云山庄的高手们所居住的二楼，傲云山庄内的
人都居住于此，拥有浓烈的肃杀味道，所以，在这里你要特
别的的小心谨慎，以免进入了不该进入的房间。

左边是琳姊(linda)的房间，右方则是张拾来(assassin)的神秘地带．

LONG);
	setup();
	replace_program(ROOM);
}
