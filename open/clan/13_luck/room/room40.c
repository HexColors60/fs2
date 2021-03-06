inherit ROOM;
void create() {
	set( "short", "客栈正厅" );
	set( "object", ([
		"file5"    : "/open/mon/obj/ghost-helmet",
		"amount7"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount4"  : 1,
		"file3"    : "/daemon/class/blademan/obj/ublade",
		"amount1"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"amount9"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"file7"    : "/open/snow/obj/figring",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/capital/obj/blade2",
	]) );
	set( "build", 10320 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room96",
		"east"      : "/open/clan/13_luck/room/room42.c",
		"down"      : "/open/clan/13_luck/room/room9.c",
		"烟雨楼"    : "/open/clan/13_luck/room/room43.c",
		"west"      : "/open/clan/13_luck/room/room41.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    欢迎您来到十三吉祥的客栈正厅，请先向柜枱的店小二CHECK IN
办理好手续后，您就可以回到妳的厢房休息了，如有需要任何服务请
直拨CT频道将有专人为您服务～～
                                               谢谢光临 ！！

             从正厅往前走，即是‘烟雨楼’。
             从左厅往前走，即是‘凤凰楼’。
             从右听往前走，即是‘望月楼’。

LONG);
	setup();
	replace_program(ROOM);
}
