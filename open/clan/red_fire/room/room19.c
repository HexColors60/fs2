// Room : /open/clan/red_fire/room/room19.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "红莲教" );
	set( "no_transmit", 1 );
	set( "light_up", 1 );
	set( "short", "$HIC$【$HIR$红莲教 $HIY$钱庄$HIC$】$NOR$" );
	set( "build", 10325 );
	set( "exits", ([ /* sizeof() == 1 */
  "east" : "/open/clan/red_fire/room/room17.c",
]) );
	set( "long", @LONG

                               $HIR$● $HIY$钱  庄 $HIR$●$NOR$

        这里是$HIR$红莲教$NOR$的$HIY$钱庄$NOR$，不过，嘿.....嘿.....嘿.....它只负责 $HIM$A$NOR$ 钱
        ，不负责其他业务，因为帮派的发展是要靠各位帮众们的努力，有钱
        者出钱，有力者出力，有好的意见者就提供出来，这样帮派才能进步
        ，而这些都是需要庞大的$HIY$资金$NOR$才行，所以大家可以把钱存在这里。



LONG);
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	setup();

	}
