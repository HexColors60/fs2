// Room : /open/clan/sky-wu-chi/room/room39.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "clan_room", "天道无极" );
	set( "long", @LONG
这里是天道无极帮下帮众所休息，闲聊的场所，
要是你觉得累了,可以在此地稍做休息,与人聊一聊天
,大家都会很欢迎你的.不论你是新帮众或是老一辈的
玩家，在此休息绝对是你最佳的选择。除了休息。往
上也是通往帮中人员房间的道路。

LONG);
	set( "short", "天萝密林" );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "no_transmit", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"east"      : "/open/clan/sky-wu-chi/room/room38",
]) );
	set( "no_clean_up", 0 );
	set( "cmkroom", 1 );
	setup();

	}
