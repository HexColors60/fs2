inherit ROOM;
void create() {
	set( "short", "$HIW$侧房$NOR$" );
	set( "owner", "timekiller" );
	set( "object", ([
		"file6"    : "/open/killer/headkill/obj/w_dag",
		"amount8"  : 1,
		"file2"    : "/open/wu/npc/obj/armband",
		"amount5"  : 1,
		"file5"    : "/open/gsword/obj/may_ring",
		"amount1"  : 1,
		"amount6"  : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount10" : 1,
		"amount2"  : 1,
		"file7"    : "/open/gblade/obj/sa-head",
		"file3"    : "/open/gblade/obj/sa-head",
		"amount4"  : 1,
		"file9"    : "/obj/gift/xiandan",
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/mogi/castle/obj/lochagem",
		"amount9"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 13785 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room242",
		"north"     : "/open/clan/sky-wu-chi/room/room222",
	]) );
	set( "long", @LONG
这里是霹雳猫的小房间，里面有一台小小的电脑，似乎正在运转中
哈.. 原来才PII - 300MHZ，什么年代了，还在用P-II，
喔..  不过这台SamSung 753DF的萤幕看起来挺高级的，
还算有点本钱，电脑好像正在执行ZMud，可是人却没在电脑前面，
一定是给我在跑rebot，你中心突然有股歪念，嘿嘿.........
偷偷把他sui...  ^oo^

LONG);
	setup();
	replace_program(ROOM);
}
