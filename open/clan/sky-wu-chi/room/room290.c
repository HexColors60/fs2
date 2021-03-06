inherit ROOM;
void create() {
	set( "short", "‘Pill’收藏二馆" );
	set( "owner", "bbsman" );
	set( "object", ([
		"file2"    : "/open/mogi/castle/obj/sspill",
		"amount7"  : 1,
		"amount3"  : 12,
		"amount2"  : 1,
		"file4"    : "/open/doctor/pill/gnd_pill",
		"file3"    : "/open/doctor/pill/human_pill",
		"amount6"  : 6,
		"file7"    : "/open/mogi/castle/obj/sspill",
		"amount5"  : 1,
		"amount1"  : 2,
		"file6"    : "/open/doctor/pill/gnd_pill",
		"file5"    : "/open/mogi/castle/obj/sspill",
		"file1"    : "/open/doctor/pill/sky_pill",
		"amount4"  : 10,
	]) );
	set( "build", 10072 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room344",
	]) );
	set( "long", @LONG
这里收藏着‘屠龙刀’从各地收集而来的丹药。天山
雪莲、高丽人蔘、东海冰精都是这里的常见物品。除了一
些常见的丹药外，如果你也有多余稀奇的丹药，也许大家
可以来交换一下。书柜中有本伤寒杂病论的精装本，是不
错的课外读物。
LONG);
	setup();
	replace_program(ROOM);
}
