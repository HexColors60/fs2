inherit ROOM;
void create() {
	set( "short", "山庄大道" );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room124.c",
	]) );
	set( "long", @LONG
通往傲云山庄内的道路，左右路旁插满着各　　
门各派的敬贺标语，还有受聘于傲云山庄的武师　　
们，庄前大道何其威武，殊不知傲云山庄乃武林　　
中第一大帮，普通人等岂可轻松进入庄内，故庄　　
前有着非常严厉的关卡把守着．

LONG);
	setup();
	replace_program(ROOM);
}
