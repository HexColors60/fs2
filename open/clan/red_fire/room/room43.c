// Room : /open/clan/red_fire/room/room43.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIY$【$HIR$红莲$HIC$护城河 $HIM$东门大桥$HIY$】$NOR$" );
	set( "owner", "reuben" );
	set( "object", ([
		"file4"    : "/open/ping/obj/poison_pill",
		"amount5"  : 20000,
		"file1"    : "/open/mon/obj/ghost-cloak",
		"file9"    : "/open/dancer/obj/magicbook",
		"amount7"  : 1,
		"amount9"  : 1,
		"amount2"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/mon/obj/ghost-legging",
		"file8"    : "/open/doctor/pill/ice_pill",
		"amount10" : 20000,
		"file2"    : "/open/mon/obj/ghost-helmet",
		"file10"   : "/open/killer/obj/bellstar",
		"amount6"  : 1,
		"file5"    : "/open/killer/obj/bellstar",
		"file7"    : "/open/mon/obj/ghost-claw",
		"amount1"  : 1,
		"amount8"  : 216,
		"file6"    : "/open/dancer/obj/yuawaist",
		"amount4"  : 4,
	]) );
	set( "outdoors", "/open/clan/red_fire" );
	set( "build", 10083 );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "light_up", 1 );
	set( "long", @LONG
你站在$HIM$桥上$NOR$，向下望着$HIC$护城河$NOR$，好清澈的河水啊，疑？....河底好像
刻了一些$HIW$字$NOR$，怪哉？！是谁有那么大的能耐潜入河水中刻$HIW$字$NOR$啊？真想跳下
去看一看......呵呵呵！......$HIY$南北$NOR$两边都有耶！先跳哪一边啊？！....
..跳下去还起的来吗？......管他的，跳了再说！！


LONG);
	set( "clan_room", "红莲教" );
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 3 */
		"west"      : "/open/clan/red_fire/room/room42.c",
		"northdown" : "/open/clan/red_fire/room/room52",
		"southdown" : "/open/clan/red_fire/room/room49",
]) );
	setup();

	}
