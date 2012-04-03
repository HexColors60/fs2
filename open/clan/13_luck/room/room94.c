inherit ROOM;
void create() {
	set( "short", "烟雨楼十楼" );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room97.c",
		"west"      : "/open/clan/13_luck/room/room113.c",
		"down"      : "/open/clan/13_luck/room/room90.c",
		"east"      : "/open/clan/13_luck/room/room118",
		"south"     : "/open/clan/13_luck/room/room95.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    客官欢迎您来到烟雨楼十楼，您所定下的厢房已经清理干净了。
从房内的窗户往外看可以将十三吉祥的全貌尽收眼底，从这终于可以
看清楚北方的宫殿，蓝色的屋檐多么美丽，从天上还有一道白色的光
线拢照着此宫殿，想必这一定是十三吉祥的总坛了。

LONG);
	setup();
	replace_program(ROOM);
}
