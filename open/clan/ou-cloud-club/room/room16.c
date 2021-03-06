// Room : /open/clan/ou-cloud-club/room/room16.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
这里是傲云山庄的高手们所居住的地方，傲云山庄内的
人都居住于此，拥有浓烈的肃杀味道，所以，在这里你要特
别的的小心谨慎，以免进入了不该进入的房间。

左边是旎旎(neonn)的家，右边则是飞燕(devil)之发呆房．

LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "cmkroom", 1 );
	set( "clan_room", "傲云山庄" );
	set( "short", "$HIY$傲$HIC$云$NOR$居" );
	set( "object", ([
		"file8"    : "/open/killer/obj/bellstar",
		"file6"    : "/open/killer/obj/bellstar",
		"amount6"  : 99999,
		"amount3"  : 99999,
		"amount5"  : 99999,
		"amount1"  : 99999,
		"amount4"  : 99999,
		"file1"    : "/open/killer/obj/bellstar",
		"file3"    : "/open/killer/obj/bellstar",
		"file7"    : "/open/killer/obj/bellstar",
		"amount7"  : 99999,
		"amount10" : 99999,
		"file9"    : "/open/killer/obj/bellstar",
		"amount9"  : 99999,
		"amount8"  : 99335,
		"file10"   : "/open/killer/obj/bellstar",
		"file5"    : "/open/killer/obj/bellstar",
		"file4"    : "/open/killer/obj/bellstar",
		"amount2"  : 99999,
		"file2"    : "/open/killer/obj/bellstar",
	]) );
	set( "build", 10619 );
	set( "exits", ([ /* sizeof() == 1 */
		"west"      : "/open/clan/ou-cloud-club/room/room140",
		"north"     : "/open/clan/ou-cloud-club/room/room18",
		"east"      : "/open/clan/ou-cloud-club/room/room139.c",
		"south"     : "/open/clan/ou-cloud-club/room/room122.c",
]) );
	set( "light_up", 1 );
	setup();

	}
