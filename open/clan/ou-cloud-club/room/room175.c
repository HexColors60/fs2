inherit ROOM;
void create() {
	set( "short", "神秘芭乐园" );
	set( "light_up", 1 );
	set( "owner", "sisao" );
	set( "object", ([
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"file4"    : "/open/sky/obj11/orange-crystal",
		"amount8"  : 5,
		"file9"    : "/open/mogi/castle/obj/blood-water",
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"amount10" : 1,
		"file3"    : "/open/mogi/castle/obj/sspill",
		"file7"    : "/open/mogi/castle/obj/sspill",
		"amount6"  : 39,
		"amount4"  : 1,
		"amount2"  : 4,
		"amount3"  : 340,
		"amount9"  : 1,
		"amount5"  : 500,
		"amount7"  : 50,
		"file2"    : "/open/mogi/dragon/obj/power",
		"amount1"  : 250,
		"file10"   : "/open/dancer/obj/maple_ribbon",
		"file8"    : "/open/mogi/castle/obj/blood-water",
	]) );
	set( "build", 10830 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room150",
	]) );
	set( "long", @LONG
这里是小雯埋一些难得的宝物的地方,外表看起来是一般的芭乐园实际
尚在地下有小雯四处蒐集来的宝物,只有在火焰鸭和小雯要去挑战焚天
魔王的时候才有可能用到,此处受到非常严密的看守,若是没有火焰鸭
和小雯的允许,还是快离开吧.

LONG);
	setup();
	replace_program(ROOM);
}
