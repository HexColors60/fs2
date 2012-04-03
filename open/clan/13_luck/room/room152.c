inherit ROOM;
void create() {
	set( "short", "雾之林入口" );
	set( "build", 10452 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room157",
		"west"      : "/open/clan/13_luck/room/room153.c",
	]) );
	set( "long", @LONG

　　你已来到了雾之林的入口处了，旁边插着一块警告牌，上头写着
‘雾之林，终年浓雾不散，越往里去，雾气越是浓密，没事者，切忽
擅闯，以免迷失在其中’。看到这在往里头望去，果真是白茫茫的一
片浓雾笼罩着一切，令你心有余悸。

LONG);
	setup();
	replace_program(ROOM);
}
