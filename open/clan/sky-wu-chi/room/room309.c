inherit ROOM;
void create() {
	set( "short", "$MAG$【缥缈空间】$NOR$" );
	set( "owner", "peiyi" );
	set( "object", ([
		"amount10" : 1,
		"file4"    : "/open/poison/obj/pearl",
		"amount2"  : 1,
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"amount6"  : 1,
		"file10"   : "/open/mon/obj/ghost-helmet",
		"amount3"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"file9"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
		"amount9"  : 1,
		"amount8"  : 1,
		"file5"    : "/daemon/class/blademan/obj/shield",
		"file8"    : "/open/ping/obj/cloud_fan",
		"amount1"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/mon/obj/ghost-legging",
		"file1"    : "/open/mon/obj/ghost-helmet",
	]) );
	set( "build", 11625 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room74",
	]) );
	set( "long", @LONG
一踏进此处，顿然觉得重心全失，身体轻得似乎要飘了起来，四周
氤氲缭绕，不着边际，这里是小佩佩平常练跳舞的场所。这里是一处非
常神奇的地方，重力与旁边的地区不一样，所以在这里的人会觉得自己
似乎能飞了起来，也因为如此，小佩佩选择了此处定居，在这里练习高
级的跳舞技术，这里还有一项神奇的功能，就是可以把法术的威力扩大
好几倍，这让小佩佩在冥思的时候，脑筋可以更清楚的想出一些奇特的
舞步。

LONG);
	setup();
	replace_program(ROOM);
}
