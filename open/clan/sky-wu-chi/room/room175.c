inherit ROOM;
void create() {
	set( "short", "机器人一号之制造工厂" );
	set( "owner", "biwem" );
	set( "object", ([
		"amount7"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/capital/room/king/obj/km-belt",
		"file4"    : "/open/tendo/obj/chaosbelt",
		"amount2"  : 1,
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file2"    : "/open/capital/room/king/obj/km-belt",
		"file10"   : "/open/mon/obj/ghost-claw",
		"amount4"  : 1,
		"file9"    : "/open/capital/room/king/obj/km-cloak",
		"amount9"  : 1,
		"file5"    : "/open/capital/room/king/obj/km-belt",
		"amount5"  : 1,
		"file7"    : "/open/capital/room/king/obj/km-belt",
		"file6"    : "/open/capital/room/king/obj/km-belt",
		"file8"    : "/open/capital/room/king/obj/km-boots",
		"amount8"  : 1,
	]) );
	set( "build", 10029 );
	set( "exits", ([
		"up"        : "/open/clan/sky-wu-chi/room/room278.c",
		"north"     : "/open/clan/sky-wu-chi/room/room279.c",
		"south"     : "/open/clan/sky-wu-chi/room/room70.c",
		"enter"     : "/open/clan/sky-wu-chi/room/room272.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"east"      : "/open/clan/sky-wu-chi/room/room280.c",
		"down"      : "/open/clan/sky-wu-chi/room/room176",
		"west"      : "/open/clan/sky-wu-chi/room/room281.c",
	]) );
	set( "long", @LONG
地窖门一开,阵阵醇厚的醇酯香便扑鼻而来,
你虽被眼前的黑暗笼罩着,
但这诱人的酒香驱使你一探究竟,
忽然一阵寒风由下方涌出,
你走到最下阶才发现地板滑滑湿湿的,
蹲下来一摸,才发觉是冰块,
冰块加上暗藏的陈年好酒,让你不禁羡慕起思量优裕的生活,
$HIC$燕仔$NOR$又如幽魂班从旁冒出,
双眼一瞪 喝道{你几时偷藏这些好酒?不会又偷花公费吧?}
LONG);
	setup();
	replace_program(ROOM);
}
