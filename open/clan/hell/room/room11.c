inherit ROOM;
void create() {
	set( "short", "$HIC$冰雪神戒$NOR$存放区" );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/open/ping/obj/ring-2",
		"file1"    : "/open/ping/obj/ring-2",
		"amount1"  : 1,
	]) );
	set( "build", 11208 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room39",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
加入地府的帮众相信都有一定程度的水准,拿到冰雪神戒都没有啥问题了
然而为了应付帮中许多只大米虫,ect.$HIR$kalin,blur,nirvana$NOR$这些懒的快爆炸的
帮众,小敏帮主还是做了一间房间存放冰雪神戒,如果想放机器人又懒的去打的
话,可以来这里拿,当然新手帮众更可以来此取用

LONG);
	setup();
	replace_program(ROOM);
}
