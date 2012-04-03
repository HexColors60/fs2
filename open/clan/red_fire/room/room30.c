// Room : /open/clan/red_fire/room/room30.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIY$【$HIR$红莲$HIC$护城河 $HIM$南门大桥$HIY$】$NOR$" );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "light_up", 1 );
	set( "long", @LONG
你站在$HIM$桥上$NOR$，向下望着$HIC$护城河$NOR$，好清澈的河水啊，疑？....河底好像
刻了一些$HIW$字$NOR$，怪哉？！是谁有那么大的能耐潜入河水中刻$HIW$字$NOR$啊？真想跳下
去看一看......呵呵呵！......$HIY$东西$NOR$两边都有耶！先跳哪一边啊？！....
..跳下去还起的来吗？......管他的，跳了再说！！


LONG);
	set( "clan_room", "红莲教" );
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 4 */
		"eastdown"  : "/open/clan/red_fire/room/room67",
		"north"     : "/open/clan/red_fire/room/room34.c",
		"south"     : "/open/clan/red_fire/room/room13.c",
		"westdown"  : "/open/clan/red_fire/room/room66",
]) );
	setup();

	}
