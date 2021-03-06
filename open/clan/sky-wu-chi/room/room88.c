// Room : /open/clan/sky-wu-chi/room/room88.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "天道无极" );
	set( "short", "通道尽头" );
	set( "object", ([
		"file6"    : "/daemon/class/bonze/puty_pullium",
		"file2"    : "/open/ping/obj/chilin_legging",
		"file4"    : "/open/port/obj/wolf_ring",
		"amount3"  : 1,
		"amount2"  : 1,
		"file1"    : "/open/gsword/obj/boots",
		"amount1"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/ping/obj/gold_hand",
		"amount5"  : 1,
		"file5"    : "/open/gsword/obj/yuskirt",
	]) );
	set( "light_up", 1 );
	set( "owner", "aow" );
	set( "build", 10400 );
	set( "long", @LONG
这里是通道的尽头，来到这儿你不禁憋住呼吸，神经紧
张的东张西望，仿佛有什么东西会突然从尽头冒出来。但你
放眼望去，那尽头却又散发着和煦的光芒，这下你可丈二金
钢般摸不着头脑了。你低下头，将脚步轻轻提起，小心翼翼
的往尽头处走去，一边走心中还一边唸着阿弥陀佛，恨不得
这时佛祖就在你身边。

LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
		"south"     : "/open/clan/sky-wu-chi/room/room84",
]) );
	set( "cmkroom", 1 );
	setup();

	}
