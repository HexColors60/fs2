// Room : /open/clan/ou-cloud-club/room/room65.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$恶魔城$HIR$大竞技场$NOR$" );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 1 */
  "east" : "/open/clan/ou-cloud-club/room/room64",
]) );
	set( "clan_room", "傲云山庄" );
	set( "long", @LONG
焦黄的的地板,严重剥落以及具有刻凿痕迹的石壁,显示
这里是上古时期格斗击技比赛的使用场遗迹,或许德古拉在
他永世不朽的生命中,亦嚐试磨练武技?或者仅仅作为观赏
战士生死相搏的娱乐场所!?先不论这点,你已见到面前有不少
骷髅战士正全副武装,聚精会神的比画着,对于你的到来,似乎
完全没有注意到...
LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
