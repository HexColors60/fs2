inherit ROOM;
void create() {
	set( "short", "$BLU$无亟魔道$NOR$" );
	set( "owner", "del" );
	set( "object", ([
		"file1"    : "/open/fire-hole/obj/b-pill",
		"amount8"  : 100,
		"file5"    : "/open/fire-hole/obj/k-pill",
		"file8"    : "/open/fire-hole/obj/w-pill",
		"file2"    : "/open/fire-hole/obj/p-pill",
		"amount4"  : 450,
		"amount3"  : 140,
		"amount5"  : 55,
		"file3"    : "/open/mogi/castle/obj/sspill",
		"amount2"  : 228,
		"amount7"  : 30,
		"amount6"  : 12,
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"amount9"  : 350,
		"file7"    : "/open/fire-hole/obj/y-pill",
		"file10"   : "/open/dancer/obj/yuawaist",
		"file4"    : "/open/fire-hole/obj/r-pill",
		"file9"    : "/open/fire-hole/obj/g-pill",
		"amount1"  : 67,
		"amount10" : 1,
	]) );
	set( "build", 10950 );
	set( "exits", ([
		"jump"      : "/open/clan/ou-cloud-club/room/room306",
		"westup"    : "/open/clan/ou-cloud-club/room/room201.c",
		"out"       : "/open/clan/ou-cloud-club/room/room230",
	]) );
	set( "long", @LONG
沿着阶梯缓缓而下，来到了一间空无一物的石室，光线
是从较为上层的石壁透光而来，仔细端详才发现四周围的墙
上，地面，甚至是天花板都有着密密麻麻、深浅不一的刀痕
，看来像是历经多次刀意的淬炼才会如此。左手边的墙壁上
有一个半人高的凹陷处，里面放了五颜六色的药丸。
□
LONG);
	setup();
	replace_program(ROOM);
}
