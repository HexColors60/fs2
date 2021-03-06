inherit ROOM;
void create() {
	set( "short", "$CYN$望 $RED$萍 $GRN$轩$NOR$" );
	set( "object", ([
		"file8"    : "/daemon/class/blademan/obj/shield",
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount8"  : 1,
		"file3"    : "/open/wu/npc/obj/armband",
		"amount7"  : 1,
		"file7"    : "/daemon/class/bonze/puty_pullium",
		"amount9"  : 1,
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file10"   : "/open/dancer/obj/yuawaist",
		"amount1"  : 1,
		"file1"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount3"  : 1,
		"amount10" : 1,
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
	]) );
	set( "owner", "speed" );
	set( "build", 10232 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room257",
		"east"      : "/open/clan/ou-cloud-club/room/room246",
	]) );
	set( "long", @LONG
这里是speed 的家, 每当想起家萍时, 他就会
一个人到这里来静静沉思, 后悔当时做的错误决定
现在只期盼有一天家萍会回到他的身边. 墙壁上刻
着当初送给家萍的诗, 上面写着 :

              句  锺 令  [32m萍[0m  [32m家[0m    
              句  [31m爱[0m [36m吾[0m  水  喻
              真  一 初  相  户
              情  生 识  逢  晓
              皆  亦 便  东  声
              为  不 顷  吴  如
              [35m妳[0m  悔 心  里  莺                         



LONG);
	setup();
	replace_program(ROOM);
}
