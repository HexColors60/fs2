inherit ROOM;
void create() {
	set( "short", "安迪专用武器室" );
	set( "owner", "andy" );
	set( "object", ([
		"file4"    : "/open/mon/obj/ghost-claw",
		"amount8"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/mon/obj/ghost-helmet",
		"file3"    : "/open/mon/obj/ghost-legging",
		"file8"    : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/main/obj/et_sword",
		"amount1"  : 1,
		"amount10" : 1,
		"file1"    : "/open/mon/obj/ghost-cloak",
		"file7"    : "/open/mon/obj/ghost-claw",
		"file9"    : "/open/mon/obj/ghost-helmet",
		"file10"   : "/open/mon/obj/ghost-helmet",
		"amount3"  : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount7"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10001 );
	set( "exits", ([
		"south"     : "/open/clan/red_fire/room/room9.c",
		"east"      : "/open/clan/red_fire/room/room74",
	]) );
	set( "long", @LONG
这里是安迪家第一大管理着的兵器房，里面放满了许许多多强
而有力的兵器，平常所找不到的通常这里都有，所以其他人是禁止
来这存取东西的。这里存放的东西通常安迪本人也很难拿到，所以
不必要的话是很少拿这里的东西的。另带一提，平常安迪用的武器
是妖纹幻爪和寒冰，请记得使用后放回。

LONG);
	setup();
	replace_program(ROOM);
}
