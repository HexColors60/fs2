inherit ROOM;
void create() {
	set( "short", "$HIG$友情$NOR$" );
	set( "object", ([
		"file3"    : "/daemon/class/fighter/armband",
		"amount3"  : 1,
		"amount5"  : 1,
		"file9"    : "/open/port/obj/wolf_ring",
		"file2"    : "/daemon/class/fighter/ywboots",
		"file8"    : "/open/ping/obj/ring-2",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/mon/obj/ghost-helmet",
		"amount9"  : 1,
		"file5"    : "/daemon/class/bonze/puty_pullium",
		"amount1"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount7"  : 1,
		"file7"    : "/open/scholar/obj/icefan",
		"amount2"  : 1,
		"file1"    : "/daemon/class/fighter/figring",
	]) );
	set( "owner", "bleak" );
	set( "light_up", 1 );
	set( "build", 10023 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room304",
		"west"      : "/open/clan/ou-cloud-club/room/room249",
	]) );
	set( "long", @LONG
世上唯一无刺的玫瑰，就是友情。
有朋友的人死得早。没有朋友的人，活着岂非和死了差不多。
一个人如果能把他的感触和他的朋友们共享，纵然无酒，也是愉快的。
聪明的主人都知道，用笑来款待客人，远比用丰盛的酒菜更令人感激。
一个人往往会在最奇怪的时候、最奇怪的地方，和一个最想不到的人变成朋友 ，
甚至他们自己都不知道这种情感是怎么来的。
LONG);
	setup();
	replace_program(ROOM);
}
