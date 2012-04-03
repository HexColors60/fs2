inherit ROOM;
void create() {
	set( "short", "$HIC$水之恋$NOR$" );
	set( "object", ([
		"file7"    : "/open/mon/obj/ghost-legging",
		"file4"    : "/daemon/class/blademan/obj/shield",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file1"    : "/open/mogi/castle/obj/lochagem",
		"amount8"  : 1,
		"file6"    : "/open/mon/obj/ghost-cloak",
		"amount7"  : 1,
		"amount1"  : 1,
		"amount4"  : 1,
		"amount9"  : 1,
		"file9"    : "/open/mon/obj/ghost-helmet",
		"file8"    : "/open/mon/obj/ghost-helmet",
		"amount5"  : 1,
		"file2"    : "/open/sky/obj/lucky_grasslink",
		"file10"   : "/open/mon/obj/ghost-legging",
		"amount10" : 1,
		"amount3"  : 1,
		"file5"    : "/open/scholar/obj/icefan",
		"amount2"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10030 );
	set( "owner", "mosia" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room217",
	]) );
	set( "long", @LONG
这是一间南北很长的房间,西边是一排糊满蝉翼纱的长窗,下半窗固定上半窗可开可阖.
北边和东墙都是依山凿石而成,房顶偏东开着亮窗,坐在窗下仰望,山上云树婆娑,瀑布
溪流宛若图画,附近绝岩泉水叮咚透窗而入.屋里陈设简单,几张杌子和茶几设在东窗下
,靠门一座金自鸣钟,尽北又一道活动门墙,摺叠起来大炕居北面南,展开隔栅门,又像一
道严严实实的屏风.
LONG);
	setup();
	replace_program(ROOM);
}
