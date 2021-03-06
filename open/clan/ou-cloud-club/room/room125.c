inherit ROOM;
void create() {
	set( "short", "$HIY$傲$HIC$云$NOR$居" );
	set( "owner", "skygod" );
	set( "object", ([
		"file4"    : "/open/love/obj/cloth1",
		"amount5"  : 1,
		"file3"    : "/open/magic-manor/obj/wood-ball",
		"amount1"  : 1,
		"file7"    : "/open/ping/obj/gold_hand",
		"amount4"  : 1,
		"file6"    : "/open/magic-manor/obj/fire-ball",
		"file5"    : "/open/scholar/obj/icefan",
		"file1"    : "/open/port/obj/wolf_ring",
		"amount6"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 10174 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room149",
		"east"      : "/open/clan/ou-cloud-club/room/room133.c",
		"west"      : "/open/clan/ou-cloud-club/room/room129.c",
		"north"     : "/open/clan/ou-cloud-club/room/room135.c",
	]) );
	set( "long", @LONG
这里是傲云山庄的高手们所居住的地方，傲云山庄内的
人都居住于此，拥有浓烈的肃杀味道，所以，在这里你要特
别的的小心谨慎，以免进入了不该进入的房间。

左边是凉(super)的家，右边则是剑神佾云(limit)的佾云居．

LONG);
	setup();
	replace_program(ROOM);
}
