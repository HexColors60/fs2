inherit ROOM;
void create() {
	set( "short", "$HIY$魔龙鳞$HIW$之界$NOR$PART2 " );
	set( "build", 10066 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room67.c",
		"west"      : "/open/clan/hell/room/room22.c",
	]) );
	set( "long", @LONG

原本魔龙麟之界只有一间...但大飞绝得不够用...因为hell的每个人都是比懒的... :P
别打我喔~ 好啦..我招了..我是最懒的...
所以还是扩充区域吧...于是魔龙灵之界part2诞生....
wahaha
祝大家使用愉快....年年有今日...岁岁有今朝......
LONG);
	setup();
	replace_program(ROOM);
}
