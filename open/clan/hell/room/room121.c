inherit ROOM;
void create() {
	set( "short", "笨蛋不得入内" );
	set( "object", ([
		"file4"    : "/open/love/obj/cloth1",
		"file3"    : "/open/love/obj/ring",
		"amount3"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/gsword/obj/ring-1",
		"file1"    : "/open/gsword/obj/no_tax",
		"amount1"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 13164 );
	set( "owner", "shenghua" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room122",
	]) );
	set( "long", @LONG
此地初建, 空无一物。
LONG);
	setup();
	replace_program(ROOM);
}
