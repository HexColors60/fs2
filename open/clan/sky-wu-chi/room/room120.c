// Room : /open/clan/sky-wu-chi/room/room120.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$【$HIC$元气门$HIW$】$NOR$" );
	set( "object", ([
		"amount9"  : 1,
		"file7"    : "/open/ping/obj/chilin_legging",
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"file6"    : "/open/tendo/obj/chaosbelt",
		"file5"    : "/open/mogi/castle/obj/lochagem",
		"amount2"  : 1,
		"file10"   : "/daemon/class/fighter/armband",
		"amount8"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/gsword/obj/yuskirt",
		"amount7"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file9"    : "/daemon/class/bonze/puty_pullium",
		"file4"    : "/open/ping/obj/gold_hand",
		"amount10" : 1,
		"file2"    : "/daemon/class/blademan/obj/shield",
	]) );
	set( "owner", "timekiller" );
	set( "light_up", 1 );
	set( "build", 10160 );
	set( "cmkroom", 1 );
	set( "long", @LONG
你往大门走近一看，门口上面大大正正的写了二个字$HIC$元气$NOR$(vigor)，你一看就明白了
这是霹雳猫所居住的地方，怪不得这边传来一阵阵的猫味，前面的两名猫侍卫大概不
会让你轻易通过吧，你心想，如果给他们一点Diamond，也许，就能见到霹雳猫本人了。

LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"enter"     : "/open/clan/sky-wu-chi/room/room242.c",
]) );
	set( "clan_room", "天道无极" );
	setup();

	}
