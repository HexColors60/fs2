inherit ROOM;
void create() {
	set( "short", "神秘后花园" );
	set( "owner", "ywarter" );
	set( "object", ([
		"amount3"  : 1,
		"amount4"  : 1,
		"file5"    : "/open/killer/obj/k_ring",
		"file3"    : "/open/ping/questsfan/obj/diamond_skirt",
		"file2"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"amount5"  : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/ping/questsfan/obj/diamond_legging",
		"file6"    : "/open/magic-manor/obj/water-ball",
		"file1"    : "/open/ping/questsfan/obj/diamond_cloak",
	]) );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "build", 12000 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room136",
	]) );
	set( "long", @LONG
这里是整个居所的后花园，也是空瓶子和他的几位夫人一起赏花看风景
的地方，这里的花都是一些奇珍异草，其中里面有一株[1;37m‘[1;35m萍音兰草[1;37m’[0m最是珍
贵，而你绝对想不到这草有怎样的功用。问了一下原来才知道这奇草原来是
个非常时期的延年续命丹之功用，吃下去之后你会感到你在这世界上有多可
以多活个二十几年，只是你也只能看而不能吃。因为当你偷摘来吃之时你会
被空瓶子当场发出猎杀令把你给杀了。所以也只能看看这里的风景，这个花
园真的是很大，有着广大的草坪还有群群的羊和马。眼睛一看那带头的马儿
原来是有名的龙驹看牠扬起头英姿的样子，你开始觉得也只有这样子的好马
才配的上这个房子的主人。

LONG);
	setup();
	replace_program(ROOM);
}
