inherit ROOM;
void create() {
	set( "short", "$HIM$软软$RED$地狱$NOR$" );
	set( "build", 60 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/hell/room/hall.c",
		"down"      : "/open/clan/hell/room/room9.c",
		"west"      : "/open/clan/hell/room/room19.c",
		"east"      : "/open/clan/hell/room/room20",
	]) );
	set( "long", @LONG
    这里是$MAG$软软$HIR$地狱$NOR$，你可以看到这个地狱的掌管者-又小又软站在这里。
他正专心的看着到这个地狱受罚的小鬼们，嘴角还露出一丝邪恶的微笑。
看来真是让人胆颤心惊!!!!!突然他转过头来对你奸笑几声，你不禁吓了一大跳!!!
心里直想着 : 还是快点离开这个鬼地方好了，不然下一个又小又软的就是我了

   又小又软的尸体(Corpse)
LONG);
	setup();
	replace_program(ROOM);
}
