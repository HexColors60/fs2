inherit ROOM;
void create() {
	set( "short", "ζ防具室ζ" );
	set( "owner", "son" );
	set( "build", 10003 );
	set( "exits", ([
		"east"      : "/open/clan/demon_castle/room/room4",
	]) );
	set( "long", @LONG
此地初建, 空无一物。
LONG);
	setup();
	replace_program(ROOM);
}
