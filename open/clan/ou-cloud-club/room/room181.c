inherit ROOM;
void create() {
	set( "short", "$HIC$傲$HIW$云$NOR$阁" );
	set( "build", 10313 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room176.c",
		"east"      : "/open/clan/ou-cloud-club/room/room185.c",
		"west"      : "/open/clan/ou-cloud-club/room/room23.c",
		"north"     : "/open/clan/ou-cloud-club/room/room184",
	]) );
	set( "long", @LONG
这里是傲云山庄的高手们所居住的二楼，傲云山庄内的
人都居住于此，拥有浓烈的肃杀味道，所以，在这里你要特
别的的小心谨慎，以免进入了不该进入的房间。

左边是迪客(dico)的房间，右边则是偶不基到(dunno)之房．

LONG);
	setup();
	replace_program(ROOM);
}
