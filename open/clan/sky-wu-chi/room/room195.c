inherit ROOM;
void create() {
	set( "short", "芷卉园" );
	set( "object", ([
		"amount6"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10737 );
	set( "owner", "jsa" );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room200.c",
		"east"      : "/open/clan/sky-wu-chi/room/room183",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
九重葛架成的花廊在你的上方展成一片绿荫，紫红
色的花朵随着微风轻轻摇曳着，显得婀娜多姿；园中遍
植各色花木，一年四季因时绽放蓓蕾，另有两盆特别用
雕花白玉盆养着的芙蓉花，品名‘清露’、‘雨月’，
皆重重叠瓣清香淡淡，‘清露’酷爱饮朝露而散清芬，
‘雨月’偏好在近满月的雨夜里挺起一身冷艳，倒是两
株奇异的花朵。
LONG);
	setup();
	replace_program(ROOM);
}
