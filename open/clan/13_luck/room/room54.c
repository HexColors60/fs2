inherit ROOM;
void create() {
	set( "short", "烟雨楼三楼" );
	set( "build", 60 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room148",
		"north"     : "/open/clan/13_luck/room/room61.c",
		"down"      : "/open/clan/13_luck/room/room53",
		"east"      : "/open/clan/13_luck/room/room59.c",
		"south"     : "/open/clan/13_luck/room/room66.c",
		"up"        : "/open/clan/13_luck/room/room71.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    客官欢迎您来到烟雨楼三楼，您所定下的厢房已经清理干净了。
从房内的窗户往外看可以将十三吉祥的全貌尽收眼底，往北边看去，
妳看到有一条白色的迷雾冲往天际，妳很好奇那到底通往哪呢？今天
晚上先好好的睡一觉，明天再去一看究竟。

LONG);
	setup();
	replace_program(ROOM);
}
