inherit ROOM;
void create() {
	set( "short", "$HIC$【舞蹈服装专柜】$NOR$" );
	set( "owner", "peiyi" );
	set( "object", ([
		"amount6"  : 1,
		"file4"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount9"  : 1,
		"file3"    : "/open/killer/obj/k_ring",
		"file10"   : "/open/gsword/obj/may_ring",
		"file8"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount4"  : 1,
		"file1"    : "/open/killer/obj/k_ring",
		"amount8"  : 1,
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"file2"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount1"  : 1,
		"file7"    : "/open/poison/obj/pearl",
		"amount10" : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"file6"    : "/open/mon/obj/ghost-claw",
		"amount2"  : 1,
	]) );
	set( "build", 10869 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room226",
	]) );
	set( "long", @LONG
    打开东边的小柜子，你可以发现许多漂亮的衣服，有红的、蓝的、
黄的、紫的、还有花样的衣服，看的你是眼花撩乱，又赞叹不已。在一
堆炫丽的服装下面，也有几件素色的衣服，有白色的洋装，黑色的晚礼
服，有传统中国服饰的旗袍，也有开高叉的裙子，还有短短的迷你裙，
看来小佩佩是个爱打扮的小女生。

LONG);
	setup();
	replace_program(ROOM);
}
