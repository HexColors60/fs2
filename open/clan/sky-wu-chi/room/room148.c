inherit ROOM;
void create() {
	set( "short", "仙云居" );
	set( "owner", "herozero" );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"west"      : "/open/clan/sky-wu-chi/room/room96",
	]) );
	set( "object", ([
		"amount4"  : 1,
		"file2"    : "/open/doctor/pill/sky_pill",
		"amount6"  : 4,
		"amount9"  : 1,
		"file6"    : "/open/doctor/pill/ice_pill",
		"file8"    : "/open/doctor/pill/gnd_pill",
		"amount5"  : 1,
		"file1"    : "/open/mogi/castle/obj/blood-water",
		"amount3"  : 1,
		"amount1"  : 4,
		"file9"    : "/obj/gift/xiandan",
		"file5"    : "/open/mogi/dragon/obj/power",
		"amount7"  : 1,
		"file3"    : "/open/mogi/castle/obj/leave",
		"file10"   : "/obj/gift/hobowdan",
		"file4"    : "/obj/gift/lingzhi",
		"amount10" : 1,
		"file7"    : "/open/killer/obj/kill_yar_head",
		"amount2"  : 13,
		"amount8"  : 38,
	]) );
	set( "light_up", 1 );
	set( "build", 11440 );
	set( "long", @LONG
穿过一阵云雾后，你眼前出现一间不起眼的小屋，只见门前有幅对
联‘家在此山中，云深不知处’，你忽然惊觉到，有莫测高深的隐士住
在这里，推门入内，里面只有简单的陈设，炉上正煮着茶水，案上的香
烟袅袅升起，望着窗外紧临的湖泊，你的内心充满了一片宁静。
LONG);
	setup();
	replace_program(ROOM);
}
