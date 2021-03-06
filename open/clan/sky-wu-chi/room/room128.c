inherit ROOM;
void create() {
	set( "short", "$HIC$思量之家$HIW$地窖$NOR$" );
	set( "light_up", 1 );
	set( "build", 10937 );
	set( "object", ([
		"file5"    : "/open/capital/guard/gring",
		"amount9"  : 1,
		"file2"    : "/obj/gift/shenliwan",
		"amount4"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/fire-hole/obj/b-pill",
		"file9"    : "/obj/gift/xiandan",
		"amount10" : 1,
		"file6"    : "/obj/gift/unknowdan",
		"file8"    : "/open/scholar/obj/icefan",
		"amount3"  : 1,
		"file7"    : "/open/capital/room/king/obj/dagger1",
		"amount6"  : 1,
		"amount1"  : 7,
		"amount7"  : 1,
		"file10"   : "/open/mon/obj/ghost-claw",
		"amount5"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file3"    : "/daemon/class/bonze/puty_pullium",
	]) );
	set( "owner", "salicili" );
	set( "exits", ([
		"up"        : "/open/clan/sky-wu-chi/room/room41.c",
	]) );
	set( "long", @LONG
地窖门一开,阵阵醇厚的醇酯香便扑鼻而来,
这诱人的酒香驱使你一探究竟,
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
