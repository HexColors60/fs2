// Room : /open/clan/ou-cloud-club/room/room52.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$恶魔城$HIR$炼金研究栋$NOR$" );
	set( "build", 10021 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "down" : "/open/clan/ou-cloud-club/room/room53.c",
  "up" : "/open/clan/ou-cloud-club/room/room51",
]) );
	set( "clan_room", "傲云山庄" );
	set( "long", @LONG
意外的发现这是个会自动升降的小平台,公用类似于现今
的电梯,看来即使拥有强大力量,这里的主人也不愿意放弃一些
为懒惰而发明的设计呢!只不过尚未完全现代化的技术使得这平
台看起来只像是一个建筑工地使用的运输货架.
LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
