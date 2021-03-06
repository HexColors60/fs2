inherit ROOM;
void create() {
	set( "short", "烟雨楼二楼" );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room43.c",
		"east"      : "/open/clan/13_luck/room/room55.c",
		"up"        : "/open/clan/13_luck/room/room54",
		"west"      : "/open/clan/13_luck/room/room56.c",
		"north"     : "/open/clan/13_luck/room/room57.c",
		"south"     : "/open/clan/13_luck/room/room58",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    客官欢迎您来到烟雨楼二楼，您所定下的厢房已经清理干净了。
从房内的窗户往外看可以将十三吉祥的全貌尽收眼底，从早到晚灯火
通明，就算晚上睡觉大门不关也不会有小偷，在帮主小南的领导下，
十三吉祥已开始走向全盛时期了。

LONG);
	setup();
	replace_program(ROOM);
}
