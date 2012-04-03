inherit ROOM;
void create() {
	set( "short", "客栈右厅" );
	set( "object", ([
		"file7"    : "/daemon/class/blademan/obj/skykey",
		"amount8"  : 1,
		"amount2"  : 1,
		"file3"    : "/daemon/class/blademan/obj/wstone",
		"file5"    : "/daemon/class/blademan/obj/wastone",
		"amount1"  : 1,
		"amount5"  : 1,
		"file1"    : "/daemon/class/blademan/obj/gstone",
		"amount6"  : 1,
		"amount4"  : 1,
		"file6"    : "/daemon/class/blademan/obj/hstone",
		"file8"    : "/obj/gift/hobowdan",
		"amount7"  : 1,
		"amount3"  : 1,
		"file2"    : "/daemon/class/blademan/obj/fstone",
		"file4"    : "/daemon/class/blademan/obj/estone",
	]) );
	set( "build", 10809 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room40.c",
		"望月楼"    : "/open/clan/13_luck/room/room114",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    欢迎您来到十三吉祥的客栈右厅，请先向柜枱的店小二CHECK IN
办理好手续后，您就可以回到妳的厢房休息了，如有需要任何服务请
直拨CT频道将有专人为您服务～～
                                               谢谢光临 ！！

             
               从这往前走，即是‘望月楼’。
             
LONG);
	setup();
	replace_program(ROOM);
}
