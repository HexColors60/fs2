inherit ROOM;
void create() {
	set( "short", "吉祥林道" );
	set( "object", ([
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"amount4"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount10" : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10266 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room153",
		"west"      : "/open/clan/13_luck/room/room2",
	]) );
	set( "long", @LONG

　　两旁树木整齐紧靠的向前沿伸，形成一自然的林道，四周一片绿
意盎然，一阵微风吹拂而过，树叶随风摇曳，犹如一片树海似的。微
风挟带着秋天的气息，徐徐吹来令人觉的神轻气爽。阳光透过枝叶洒
下点点金黄，美不胜收。

LONG);
	setup();
	replace_program(ROOM);
}
