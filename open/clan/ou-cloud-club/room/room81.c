// Room : /open/clan/ou-cloud-club/room/room81.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIR$四极$HIY$天山$NOR$径(连结怪怪)" );
	set( "no_clean_up", 0 );
	set( "long", @LONG
这里就是传闻中的四极天山径，若没有相当足够的奇门　　
遁甲当基础，要想走过此处只怕会陷入万劫不复的地步，只　　
见周围有四个方向，个个似是而非，处处暗藏杀机，偏偏只　　
有一个才是正确的道路，叫人难以抉择．．．　　
　　
LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 5 */
  "northdown" : "/open/clan/ou-cloud-club/room/room80",
  "southup" : "/open/clan/ou-cloud-club/room/room106.c",
  "northup" : "/open/clan/ou-cloud-club/room/room105.c",
  "westup" : "/open/clan/ou-cloud-club/room/room104.c",
  "eastup" : "/open/clan/ou-cloud-club/room/room82.c",
]) );
	set( "clan_room", "傲云山庄" );
	set( "no_transmit", 1 );
	setup();

	}
