inherit ROOM;
void create() {
	set( "short", "小二的武器房间二" );
	set( "owner", "puffy" );
	set( "object", ([
		"amount9"  : 1,
		"amount1"  : 10,
		"file4"    : "/open/magic-manor/obj/fire-ball",
		"file2"    : "/open/mogi/castle/obj/seven6-dark-head",
		"file3"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount6"  : 1,
		"amount7"  : 1,
		"amount5"  : 1,
		"file8"    : "/open/ping/obj/ra-head",
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"amount3"  : 1,
		"file5"    : "/open/magic-manor/obj/wood-ball",
		"file9"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount4"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/snow/obj/sky_lin_stone",
		"amount10" : 1,
		"amount8"  : 1,
		"file6"    : "/open/gblade/obj/sa-head",
		"file1"    : "/open/mogi/dragon/obj/power",
	]) );
	set( "build", 10068 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room201",
	]) );
	set( "long", @LONG
    这里是小二的武器房间
你的眼前一阵七色光芒跟隔壁依样
地上摆着各式各样的武器
也有聚灵山庄八傻的武器嘛
小二凭藉着广大的人脉
和各方好汉蒐集了各种的武器摆在这里
看来fs里面应该没有他拿不到的优良eq了吧
此外还有各种master的优良武器
也都摆在这里
只要是不能save的这里几乎都有
LONG);
	setup();
	replace_program(ROOM);
}
