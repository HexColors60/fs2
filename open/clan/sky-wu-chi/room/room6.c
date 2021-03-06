// Room : /open/clan/sky-wu-chi/room/room6.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "天道无极" );
	set( "light_up", 1 );
	set( "long", @LONG
寂静的走道，两旁悬挂着明亮的灯火，左方似乎有着些
许光线，也许快到天道无极的天极殿了，温暖的火光照着自
己觉得格外的舒适，想不到看似冷寂的外表，竟有如此阳光
的一面，正一边享受这美好的一片时，感觉似乎好像快走到
了。

LONG);
	set( "short", "长廊 2" );
	set( "build", 27 );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/wu/obj/ring1",
	]) );
	set( "no_transmit", 1 );
	set( "exits", ([ /* sizeof() == 4 */
		"north"     : "/open/clan/sky-wu-chi/room/room82.c",
		"west"      : "/open/clan/sky-wu-chi/room/hall.c",
		"east"      : "/open/clan/sky-wu-chi/room/room105.c",
]) );
	set( "no_clean_up", 0 );
	set( "cmkroom", 1 );
	setup();

	}
