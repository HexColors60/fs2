inherit ROOM;
void create() {
	set( "short", "战斗准备室" );
	set( "owner", "bbsman" );
	set( "object", ([
		"amount7"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/port/obj/wolf_ring",
		"file1"    : "/daemon/class/bonze/puty_pullium",
		"file4"    : "/open/common/obj/liz_meat",
		"file6"    : "/daemon/class/blademan/obj/six-neck",
		"file8"    : "/open/mon/obj/ghost-helmet",
		"amount8"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/wu/npc/obj/armband",
		"file7"    : "/daemon/class/blademan/obj/shield",
		"amount9"  : 1,
		"amount3"  : 1,
		"file9"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10346 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room122",
		"west"      : "/open/clan/sky-wu-chi/room/room331",
	]) );
	set( "long", @LONG
这边是‘BBSMAN’在出发征战前的‘战斗准备室’。每
次出门前总是会来到这边，做好万全的准备才会出门。所以
看到满地零乱的武器跟防具散落一地也不足为奇了。特别的
是，左边是‘BBSMAN’穿衣服的地方，可不要跟警方说唷。
LONG);
	setup();
	replace_program(ROOM);
}
