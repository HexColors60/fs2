// Room : /open/clan/ou-cloud-club/room/room31.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$YEL$丝绸之路$NOR$" );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "long", @LONG
这里应是欧亚大陆的中心地带吧!!来往络绎不绝的骆驼商队
显示这是条重要的商业道路,而越往西前进,越能见到更多不同于
中土人民的陌生面孔,这些人大多蓝眼睛,鼻子略挺,皮肤略黑,且
多身材高大之人,虽语言不通,谈吐间却能看出非一般不识字之乡
野匹夫,或许自古以来的天朝上国,四夷臣服的观念要有所修正了
LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"west"      : "/open/clan/ou-cloud-club/room/room34",
		"east"      : "/open/clan/ou-cloud-club/room/room30.c",
]) );
	set( "no_transmit", 1 );
	set( "clan_room", "傲云山庄" );
	setup();

	}
