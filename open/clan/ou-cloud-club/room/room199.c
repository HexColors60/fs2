inherit ROOM;
void create() {
	set( "short", "$HIC$剑魔$HIM$紫云蝶$NOR$" );
	set( "object", ([
		"file10"   : "/open/gsword/obj1/sball",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/prayer/obj/boris-cloth",
		"file1"    : "/open/fire-hole/obj/w-pill",
		"amount1"  : 3,
		"amount8"  : 1,
		"amount9"  : 1,
		"amount7"  : 1,
		"file4"    : "/open/ping/obj/gold_hand",
		"amount5"  : 1,
		"amount10" : 1,
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"file3"    : "/open/gsword/obj/dragon-sword",
		"file8"    : "/open/port/obj/wolf_ring",
		"file7"    : "/open/prayer/obj/kylin-belt",
		"file5"    : "/open/ping/obj/gold_hand",
		"amount3"  : 1,
		"file2"    : "/open/mogi/castle/obj/ninepill",
	]) );
	set( "owner", "mekyn" );
	set( "build", 10066 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room17",
	]) );
	set( "long", @LONG

    走进此地，眼前一片相思竹林随风摇曳，似乎正在欢迎妳的到来
林中石阶细布如丝，耳边不时传来阵阵风铃舞动之声，仿佛人间仙乐
仔细一看，相思林中竹风飘逸不定，风吹铃动，丝丝透露出无限哀愁
正所谓相思林中长相思，柳叶秋风吹，思念忆无涯。

LONG);
	setup();
	replace_program(ROOM);
}
