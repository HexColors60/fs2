// Room : /open/clan/sky-wu-chi/room/room9.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
接下来看到的是夜行动物区，在我们左
手边的是有死亡之称的是「蝙蝠”死亡人生
，小弟弟，请不要把手放到窗外喔。。。再
来，我们看到的是。。。唉呀，小心不要让
「攘袂生”跑到车上来喔，来我们接下来去
下一区吧。
LONG);
	set( "exits", ([ /* sizeof() == 4 */
		"west"      : "/open/clan/sky-wu-chi/room/room15.c",
		"east"      : "/open/clan/sky-wu-chi/room/room20.c",
		"north"     : "/open/clan/sky-wu-chi/room/room10.c",
		"south"     : "/open/clan/sky-wu-chi/room/room8.c",
		"up"        : "/open/clan/sky-wu-chi/room/room42",
]) );
	set( "short", "走 廊 2" );
	set( "build", 906 );
	set( "no_clean_up", 0 );
	set( "clan_room", "天道无极" );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "light_up", 1 );
	setup();

	}
