inherit ROOM;
void create() {
	set( "short", "$HIC$kalin$HIW$的$HIG$鸡丝头3$NOR$" );
	set( "owner", "taxi" );
	set( "build", 10177 );
	set( "exits", ([
		"north"     : "/open/clan/hell/room/room4.c",
		"east"      : "/open/clan/hell/room/room63.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

由于各界大老忘不了kalin之前的雄风,
一直鼓动kalin复出....kalin思考了许久...
嗯...
嗯.......
嗯...........
嗯...............
z.....zz......zzzzz.....ZZZZZZ

kalin终于决定复出了!!
在周公的建议下... kalin决定附身在一个有正义感的小伙子身上,
这各小伙子平常以开计程车维生........
但只要他一感觉到有邪恶的力量入侵..残害弱小....
他就会马上找电话亭...化身为勇猛的战士...


并口中喃喃道..恶魔!让我代替月亮来惩罚你吧!!
LONG);
	setup();
	replace_program(ROOM);
}
