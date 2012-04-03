inherit ROOM;
void create() {
	set( "short", "厨房" );
	set( "object", ([
		"file5"    : "/open/mon/obj/ghost-legging",
		"amount2"  : 1,
		"amount8"  : 1,
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"file1"    : "/daemon/class/blademan/obj/shield",
		"amount9"  : 1,
		"file2"    : "/open/wu/npc/obj/armband",
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file7"    : "/open/scholar/obj/icefan",
		"file3"    : "/open/mon/obj/ghost-helmet",
		"amount5"  : 1,
		"amount1"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file6"    : "/daemon/class/bonze/puty_pullium",
		"amount7"  : 1,
		"file8"    : "/open/mon/obj/ghost-claw",
		"amount3"  : 1,
	]) );
	set( "owner", "titanic" );
	set( "build", 10050 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room53.c",
		"enter"     : "/open/clan/13_luck/room/room82",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    这是一间充满香味的厨房，一走进这里，你可以闻到这边传来阵
阵的饭香，眼前一道道美位的佳肴让你满嘴的口水直流，肚子更咕噜
咕噜的叫了起来。没想这一位圣火教嫡传弟子不但武功一流，连厨艺
都令人赞叹不已，真是莫测高深。


LONG);
	setup();
	replace_program(ROOM);
}
