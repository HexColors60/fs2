inherit ROOM;
void create() {
	set( "short", "$HIC$青霞$NOR$的$HIW$卧房$NOR$" );
	set( "owner", "waydancer" );
	set( "object", ([
		"amount6"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/mogi/dragon/obj/power",
		"file2"    : "/open/ping/obj/poison_pill",
		"amount7"  : 1,
		"amount9"  : 9,
		"amount10" : 1,
		"amount8"  : 1,
		"file6"    : "/open/killer/headkill/obj/world_dag",
		"amount1"  : 1,
		"file1"    : "/open/main/obj/firesword",
		"file5"    : "/open/capital/obj/king-ring",
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"amount3"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/capital/guard/gring",
		"amount4"  : 1,
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"file8"    : "/open/prayer/obj/dragon-ring",
		"file7"    : "/open/killer/headkill/obj/world_dag",
	]) );
	set( "build", 10050 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/red_fire/room/room96",
	]) );
	set( "long", @LONG

这是我的$HIW$卧房
$NOR$一进门看到了一张大床
这就是我$HIM$sleep$NOR$和练功的地方
室内$HIW$灯光$NOR$柔和
旁边有一扇窗
你往外看，只见一切$HIR$人$HIG$间$HIC$烟$HIY$火$NOR$尽收眼底
你不禁赞叹到 丫，$HIC$好美$NOR$


LONG);
	setup();
	replace_program(ROOM);
}
