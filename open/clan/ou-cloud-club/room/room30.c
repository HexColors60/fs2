// Room : /open/clan/ou-cloud-club/room/room30.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIY$西方极乐 $HIW$天竺$NOR$" );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "long", @LONG
你来到了一座炎热的城市,这里的人们由于长期曝晒于烈日中
的关系,皮肤都比我们黑得多,而且各种佛教寺庙林立,原来,这里
就是佛教的发源地--天竺,传闻佛教乃天竺之国教,果然传言不虚
,一路上处处可见身劈袈裟的僧侣,令人感到浓厚的宗教气息.
LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"east"      : "/open/clan/ou-cloud-club/room/room29",
		"west"      : "/open/clan/ou-cloud-club/room/room31.c",
]) );
	set( "no_transmit", 1 );
	set( "clan_room", "傲云山庄" );
	setup();

	}
