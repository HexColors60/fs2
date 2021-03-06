inherit ROOM;
void create() {
	set( "short", "兰亭阁" );
	set( "object", ([
		"amount6"  : 1,
		"file3"    : "/open/gblade/obj/sa-head",
		"file2"    : "/open/gblade/obj/sa-head",
		"amount1"  : 1,
		"amount3"  : 1,
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"file1"    : "/open/mogi/castle/obj/fire_book",
		"amount2"  : 1,
	]) );
	set( "build", 10002 );
	set( "owner", "jsa" );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room195",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
一走进房内，你竟然分辨不出隔间，原来四面皆是
雕空玲珑木板，或流云百富，或岁寒三友，或山水人物
，或翎毛花卉，或集锦，或博古，各种花样，皆是名手
雕刻，五彩销金嵌玉的。一隔一隔，或贮书，或设鼎，
或安置笔砚。其隔式样，或圆，或方，或连环半壁。且
满墙皆是随依古董玩器之形枢成的槽子，如琴，剑，悬
瓶之类，俱悬于壁，却都与壁相平的。
LONG);
	setup();
	replace_program(ROOM);
}
