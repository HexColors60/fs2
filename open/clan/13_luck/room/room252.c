inherit ROOM;
void create() {
	set( "short", "‘山脚’" );
	set( "owner", "poll" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room250",
		"north"     : "/open/clan/13_luck/room/room249",
	]) );
	set( "long", @LONG
愈往北边的山路爬上来，愈觉得空气新鲜，不像江湖上浓厚的杀气一般
。愈往山底下的景色看过去，看到刚刚遇到的那个城镇，旁边的小河也似乎
都化成咆哮的滚流，湍急得水面在阳光下闪烁着缤纷的色彩。而平常的落日
嫣霞都映照成一片美丽的景象，让你个眼睛看着目不暇给。
LONG);
	setup();
	replace_program(ROOM);
}
