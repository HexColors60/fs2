inherit ROOM;
void create() {
	set( "short", "ζ紫星堂ζ" );
	set( "object", ([
		"file10"   : "/open/port/obj/wolf_ring",
		"amount4"  : 10,
		"amount6"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/ping/obj/poison_pill",
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"amount1"  : 1,
		"amount8"  : 1,
		"amount7"  : 1,
		"amount9"  : 3,
		"file4"    : "/open/doctor/pill/f_pill",
		"amount5"  : 1,
		"amount10" : 1,
		"file8"    : "/open/prayer/obj/boris-cloth",
		"file6"    : "/open/ping/obj/gold_hand",
		"file3"    : "/open/prayer/obj/kylin-belt",
		"file7"    : "/open/ping/obj/chilin_legging",
		"file5"    : "/open/prayer/obj/boris-boots",
		"amount3"  : 1,
		"file2"    : "/open/main/obj/shiblade",
	]) );
	set( "owner", "mad" );
	set( "build", 10570 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room54.c",
		"enter"     : "/open/clan/13_luck/room/room62",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    走进此地隐约有一股无名的杀气紧盯着妳，四周的空气有如寒冰
结霜般的令妳透不过气来，寒风飕飕的吹，妳的心跳亦随着加速跳动
眼前一位神秘之人盘坐于七彩灵石之上吸收着大地精华，透露出一种
诡异的感觉，看来此处不是你久留之地，还是趁早离开为妙。

LONG);
	setup();
	replace_program(ROOM);
}
