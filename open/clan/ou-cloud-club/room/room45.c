// Room : /open/clan/ou-cloud-club/room/room45.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$恶魔城$HIR$炼金研究栋$NOR$" );
	set( "build", 10009 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "west" : "/open/clan/ou-cloud-club/room/room3",
  "east" : "/open/clan/ou-cloud-club/room/room43",
]) );
	set( "clan_room", "傲云山庄" );
	set( "long", @LONG
天花板滴着几许未知的液体,你突然想试着了解它的成分,
但随即想到德古拉伯爵的残暴血腥,或许这些东西是腐尸的尸水
或着是用来凌迟受害者的毒液,还是少碰为妙吧!!不过,这里终
归是个实验室,触手可及的,就是瓶瓶罐罐的各种化学试样,还有
许多不知名的金属材料,这就是典型炼金术的基本配备吧!?
LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
