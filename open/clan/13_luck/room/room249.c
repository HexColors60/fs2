inherit ROOM;
void create() {
	set( "short", "‘凉亭’" );
	set( "light_up", 1 );
	set( "owner", "poll" );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room248",
		"south"     : "/open/clan/13_luck/room/room252.c",
	]) );
	set( "long", @LONG
爬到了山上的最高峰，遥远的望去，可以把远方的城镇纳入眼底，而放
眼望过去，不只是远方城镇的景色，往远方的东边望过去，好像有座建筑物
造在远方的山上，只是因为距离的遥远，好像就没有看得很清楚了。而建造
在此的凉亭就是给游客们休憩的地方，而有时候城镇的百姓也会来这边爬爬
山，健健身等等。
LONG);
	setup();
	replace_program(ROOM);
}
