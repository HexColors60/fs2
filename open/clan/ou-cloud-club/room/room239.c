inherit ROOM;
void create() {
	set( "short", "$HIR$魔日$HIY$剑$HIW$室$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"amount1"  : 1,
		"amount6"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/prayer/obj/kylin-belt",
		"amount7"  : 1,
		"file4"    : "/open/mon/obj/ghost-helmet",
		"file2"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/daemon/class/blademan/obj/shield",
		"amount5"  : 1,
		"file7"    : "/daemon/class/fighter/armband",
		"file3"    : "/open/mon/obj/ghost-legging",
		"file8"    : "/open/prayer/obj/boris-boots",
		"amount4"  : 1,
		"file1"    : "/open/mon/obj/ghost-claw",
		"amount3"  : 1,
	]) );
	set( "build", 10024 );
	set( "light_up", 1 );
	set( "owner", "nickm" );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room195",
	]) );
	set( "long", @LONG

                 $HIR$☆  $HIW$魔  日  斩  $HIR$☆

$HIG$ξ雪月 风花ξ$HIY$纵身一跃，将全身功力集中于剑尖，凭空发出一击。
$RED$你反应不及，$HIR$魔日斩$RED$已全数贯穿妳的身体。
$NOR$( 妳$RED$已经陷入半昏迷状态，随时都可能摔倒晕去。$NOR$ )

$NOR$你脚下一个不稳，跌在地上一动也不动了。$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
