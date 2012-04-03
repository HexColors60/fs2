inherit ROOM;
void create() {
	set( "short", "$HIW$动物园$NOR$" );
	set( "owner", "timekiller" );
	set( "object", ([
		"amount9"  : 1,
		"file5"    : "/open/mon/obj/ghost-helmet",
		"file3"    : "/open/mon/obj/ghost-legging",
		"amount8"  : 17195,
		"file8"    : "/open/killer/obj/hate_knife",
		"file2"    : "/open/mon/obj/ghost-cloak",
		"amount10" : 90,
		"file9"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount1"  : 1,
		"amount7"  : 854,
		"file1"    : "/open/mon/obj/ghost-claw",
		"amount5"  : 1,
		"amount4"  : 1,
		"file10"   : "/open/killer/obj/black",
		"amount6"  : 80,
		"file6"    : "/open/doctor/pill/sky_pill",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"amount3"  : 1,
		"file7"    : "/open/killer/obj/s_pill",
		"amount2"  : 1,
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room223",
	]) );
	set( "build", 10950 );
	set( "long", @LONG
哇！！这里就是天道无极中的动物园了，嘿嘿～～想不到，
这里竟然是免费的，不过，里面的动物也太少只了吧，
只看到几只小狗和小猫而已，拜托，动物园这么简陋怎么行，
还是留几颗$HIW$Diamond$NOR$下来当做基金吧，
这样下次才会有更多的动物！！

LONG);
	setup();
	replace_program(ROOM);
}
