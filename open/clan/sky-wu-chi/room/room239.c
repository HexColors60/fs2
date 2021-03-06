inherit ROOM;
void create() {
	set( "short", "$WHT$玄宇宙$NOR$" );
	set( "owner", "lord" );
	set( "object", ([
		"file4"    : "/open/mon/obj/ghost-legging",
		"file2"    : "/open/mon/obj/ghost-cloak",
		"amount2"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/tendo/obj/chaosbelt",
		"file3"    : "/daemon/class/blademan/obj/shield",
		"amount9"  : 1,
		"amount7"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file8"    : "/open/dancer/obj/yuawaist",
		"file1"    : "/open/mon/obj/ghost-helmet",
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"file9"    : "/open/quests/snake/npc/obj/snake_gem",
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
		"file10"   : "/daemon/class/blademan/obj/shield",
		"amount10" : 1,
	]) );
	set( "item_desc", ([
		"map" : @ITEM
往东是$HIM$东银河系$NOR$
往西是$HIC$西银河系$NOR$
往南是$HIB$南银河系$NOR$
往北是$HIR$北银河系$NOR$
往上是$HIY$九天外天$NOR$
往下是$HIG$九地黄泉$NOR$
ITEM,
	]) );
	set( "light_up", 1 );
	set( "build", 10067 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room310",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"east"      : "/open/clan/sky-wu-chi/room/room284.c",
		"west"      : "/open/clan/sky-wu-chi/room/room249.c",
	]) );
	set( "long", @LONG
这里是小星星$HIC$星陨$NOR$平时休息的地方，里面的摆设极整齐且清朴，只见墙上挂了对刀剑
，显得极具气派，相传这对刀剑乃是雪苍派开山祖师从一位异人手中得来的，只是可惜雪
苍派开山祖师鬼影老人不会刀剑，否则传授于$HIC$星陨$NOR$必能以此刀剑扬名立万。

  $WHT$玄宇宙地图$NOR$(map)

LONG);
	setup();
	replace_program(ROOM);
}
