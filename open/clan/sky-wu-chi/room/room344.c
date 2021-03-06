inherit ROOM;
void create() {
	set( "short", "‘Pill’收藏一馆" );
	set( "owner", "bbsman" );
	set( "object", ([
		"amount4"  : 4,
		"amount2"  : 130,
		"amount6"  : 193,
		"amount7"  : 1,
		"file3"    : "/open/doctor/pill/sky_pill",
		"file7"    : "/open/mogi/castle/obj/sholo-shield",
		"amount3"  : 156,
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 155,
		"file2"    : "/open/doctor/pill/gnd_pill",
		"file1"    : "/open/doctor/pill/human_pill",
		"amount5"  : 1,
		"file4"    : "/open/ping/obj/poison_pill",
		"file6"    : "/open/doctor/pill/ice_pill",
	]) );
	set( "build", 12378 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room122.c",
		"north"     : "/open/clan/sky-wu-chi/room/room290",
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
