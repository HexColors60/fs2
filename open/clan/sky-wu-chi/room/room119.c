inherit ROOM;
void create() {
	set( "short", "$HIW$水无边$NOR$" );
	set( "owner", "bbsman" );
	set( "object", ([
		"file4"    : "/open/scholar/obj/s_wrists",
		"file3"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount6"  : 1,
		"amount9"  : 1,
		"file10"   : "/open/scholar/obj/s_hands",
		"file9"    : "/open/mogi/dragon/obj/sunblade",
		"amount4"  : 1,
		"file1"    : "/open/mogi/village/obj/b_potion",
		"file6"    : "/open/mon/obj/ghost-legging",
		"file7"    : "/obj/gift/lingzhi",
		"amount1"  : 55,
		"amount7"  : 1,
		"amount3"  : 1,
		"amount10" : 1,
	]) );
	set( "build", 10113 );
	set( "exits", ([
		"enter"     : "/open/clan/sky-wu-chi/room/room122.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
$HIC$大雪漫天，冰雪纷纷，这里冰天雪地四面都是冰地，大雪一片片
的飘落，绽放出朦胧的景象，来到这里感到冰冷刺骨，但附近有一间
小屋，里面有着暖暖的火，更是兴起了另一番景象，而旁边立起一座
大冰块上面并刻有字，正是「水无边白龙居”。$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
