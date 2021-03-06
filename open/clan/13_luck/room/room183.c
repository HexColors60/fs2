inherit ROOM;
void create() {
	set( "short", "小乌龟的房间" );
	set( "object", ([
		"amount10" : 1,
		"file7"    : "/open/mon/obj/ghost-cloak",
		"file2"    : "/open/mon/obj/ghost-claw",
		"file3"    : "/open/port/obj/wolf_ring",
		"amount5"  : 1,
		"file4"    : "/open/dancer/obj/yuawaist",
		"amount7"  : 1,
		"file5"    : "/daemon/class/blademan/obj/shield",
		"amount9"  : 1,
		"file9"    : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/dancer/obj/maple_ribbon",
		"amount1"  : 1,
		"file8"    : "/open/mon/obj/ghost-claw",
		"amount8"  : 1,
		"file10"   : "/daemon/class/blademan/obj/ublade",
		"file6"    : "/open/mon/obj/ghost-legging",
		"amount2"  : 1,
	]) );
	set( "owner", "turtle" );
	set( "build", 10561 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room369",
		"south"     : "/open/clan/13_luck/room/room101.c",
	]) );
	set( "long", @LONG

    听得金声淙淙，前有山溪。月光下溪水清澈异常，山涯下一条大瀑布
如玉龙悬空，滚滚而下，请入一作清澈异常的大湖中。瀑布注入处湖水翻
滚，只离得瀑布十余丈，湖水便一如镜，月照入中，湖心也有一个皓洁的
圆月。乌龟山洞才人出，智谋无双，运筹幄决胜千里。最本土化的语音口
白，最震撼的特效乌龟招式，最爆笑的乌龟动作表情。并提国家最多元化
的乌龟生产，霹雳超级无敌龟就站在你的前方。

LONG);
	setup();
	replace_program(ROOM);
}
