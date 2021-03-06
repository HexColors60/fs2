inherit ROOM;
void create() {
	set( "short", "刀之墓" );
	set( "owner", "zeros" );
	set( "object", ([
		"file10"   : "/open/killer/obj/k_ring",
		"amount7"  : 1,
		"amount4"  : 1,
		"file6"    : "/open/capital/guard/gring",
		"file2"    : "/daemon/class/blademan/obj/six-neck",
		"file7"    : "/open/capital/room/king/obj/dagger1",
		"amount2"  : 1,
		"amount1"  : 1,
		"amount10" : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/daemon/class/blademan/obj/ublade",
		"amount9"  : 1,
		"file5"    : "/open/ping/obj/chilin_legging",
		"amount5"  : 1,
		"amount6"  : 1,
		"file9"    : "/open/mon/obj/ghost-legging",
		"file1"    : "/open/ping/obj/ring-2",
		"amount3"  : 1,
	]) );
	set( "build", 10142 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room306.c",
		"south"     : "/open/clan/sky-wu-chi/room/room90",
		"out"       : "/open/clan/sky-wu-chi/room/hall.c",
		"north"     : "/open/clan/sky-wu-chi/room/room168.c",
	]) );
	set( "long", @LONG
这里阴风阵阵，让人不寒而栗，仔细一看，这里都是摆满了宝刀，天下
中出名的刀，在这里都可以看到，邪刀－刁，鱼龙宝刀、无名宝刀、狮
头宝刀、挂日刀一些相当成名的武器，远处看有一个杀气十足的守刀者
，凡是想要这里的刀，全都要通过他的考验才能拿的到，这个守刀者是
复数零的徒弟，这里的刀都是由复数零所挑战各方高守，所夺回的刀，
        他所夺回的刀，全都丢在这由，守刀者保管
LONG);
	setup();
	replace_program(ROOM);
}
