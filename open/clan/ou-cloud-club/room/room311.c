inherit ROOM;
void create() {
	set( "short", "----land1" );
	set( "exits", ([
		"lake"      : "/open/clan/ou-cloud-club/room/room310",
	]) );
	set( "long", @LONG
此地初建, 空无一物。
LONG);
	setup();
	replace_program(ROOM);
}
