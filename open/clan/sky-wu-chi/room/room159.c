inherit ROOM;
void create() {
	set( "short", "$HIC$【$NOR$防器房$HIC$】$NOR$小新" );
	set( "owner", "srat" );
	set( "light_up", 1 );
	set( "build", 10000 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room24",
	]) );
	set( "long", @LONG
小新家最强的防器室就是在此了，里面的防具因为不是小
新所能拿到的，所以更显得它的重要，由于只有打经验值时会
穿，所以平常是很少用到的，这里不但是小新管最严利的地方
之一，更是不能让别人来的禁地。不过当然还是有例外的时候
啦。。。哈

LONG);
	setup();
	replace_program(ROOM);
}
