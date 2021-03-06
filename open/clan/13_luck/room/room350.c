inherit ROOM;
void create() {
	set( "short", "邪刀室" );
	set( "owner", "max" );
	set( "object", ([
		"file9"    : "/daemon/class/bonze/puty_pullium",
		"file6"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount9"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount3"  : 1,
		"file1"    : "/open/main/obj/shiblade",
		"amount2"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file5"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount7"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file2"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount5"  : 1,
		"amount6"  : 1,
		"file8"    : "/open/magic-manor/obj/hwa-je-icer",
	]) );
	set( "build", 10104 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room352",
	]) );
	set( "long", @LONG

    一进入此室中，只见墙上挂着一把 [0;1;35m□[1m□[1m□[1mM[0m(Shi-blade)，刀上刻着一些
细细小小的字，仔细看去原来是魔刀‘三斩归元’刀法之一，妳聚集九天
之气，使出[35m【三斩归元～邪龙斩元】[0m‘魔[0;1;36m□[1ms[1;33m□[1m□[1;36m□[1m□[0m～～[0;1;31m□[1mI[0m天[0;1;34m□[1m□[1;36m□[1m□[0m’，皇宫禁
卫军惊愕之于，只见妳把[0;1;35m□[1m□[1m□[1mM[0m插于地上，唸起秘咒，瞬时火焰歕张淹漫整
个天际。

LONG);
	setup();
	replace_program(ROOM);
}
