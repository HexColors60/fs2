inherit ROOM;
void create() {
	set( "short", "$MAG$紫$NOR$$HIY$幽$NOR$$HIG$湖$NOR$" );
	set( "object", ([
		"amount6"  : 1,
		"file1"    : "/open/mon/obj/ghost-claw",
		"amount3"  : 1,
		"file6"    : "/open/port/obj/wolf_ring",
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"file2"    : "/open/mon/obj/ghost-cloak",
		"amount2"  : 1,
		"file4"    : "/open/wu/npc/obj/armband",
	]) );
	set( "build", 10021 );
	set( "owner", "lina" );
	set( "exits", ([
		"west"      : "/open/clan/red_fire/room/room77",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

这是一座盖在水域上的小型$HIY$金属$NOR$矿场，从远处看似一艘在水上摇曳
的$HIC$小船$NOR$，虽然这里的矿产不多，生产进度缓慢，但在这里的人似乎
一点也不以为意，瞧！他们脸上的笑容是多么快乐。在矿场旁边有
一块小小的$YEL$告示板$NOR$（Sign），上面写了一些依稀可辨的文字。


LONG);
	setup();
	replace_program(ROOM);
}
