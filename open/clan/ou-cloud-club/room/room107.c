// Room : /open/clan/ou-cloud-club/room/room107.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "build", 11433 );
	set( "cmkroom", 1 );
	set( "long", @LONG
一座广大无垠的花园，四处陈列了许多尊高大的石像，        
原来此处是白家历代帝皇的王陵，而每一尊石像，皆是历任    
海虎武神在临终前以[0;1;37m□[1m□[1m□[1m□[1m□[1mO[1m□[1mq[0m以及[0;1;31m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[0m强化保护的，所    
以才能保存千年之久，传说第[0;1;33m7[1m4[1m3[0m代海虎武神-白[0;1;32m□[1mB[1m□[1mK[0m就是在    
此领悟无敌的[0;1;30m□[1m□[1m□[1mt[1m□[1m□[1m□[1m□[1m□[1mD[0m以及[0;1;36m□[1m□[1m□[1mZ[1m□[1m□[1m□[1mD[0m等惊世绝学，而这更    
将冰焰引导进入磁场转动的[0;1;31m□[1m□[1m□[1m□[1m□[1m□[1m□[1m□[0m，但由于未能完全掌握    
[0;1;37m□[1m□[1m□[1m□[1m□[1mO[1m□[1mq[0m带来的强大反噬，非在生死关头，冰焰不会轻易在    
人前展示这些传说中的武学。

LONG);
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	set( "exits", ([ /* sizeof() == 1 */
		"east"      : "/open/clan/ou-cloud-club/room/room14.c",
		"west"      : "/open/clan/ou-cloud-club/room/room32",
]) );
	set( "clan_room", "傲云山庄" );
	set( "short", "磨刀坊" );
	set( "object", ([
		"amount8"  : 1,
		"amount6"  : 1,
		"file6"    : "/open/gsword/obj/yuskirt",
		"file4"    : "/daemon/class/bonze/puty_pullium",
		"file7"    : "/daemon/class/fighter/armband",
		"amount1"  : 1,
		"file5"    : "/open/mon/obj/ghost-cloak",
		"file8"    : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"file1"    : "/open/mon/obj/ghost-helmet",
		"amount3"  : 1,
		"amount7"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/scholar/obj/s_hands",
		"amount5"  : 1,
	]) );
	set( "owner", "moblade" );
	set( "light_up", 1 );
	setup();

	}
