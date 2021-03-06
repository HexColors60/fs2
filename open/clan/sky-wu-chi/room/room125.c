inherit ROOM;
void create() {
	set( "short", "空瓶子武器室1" );
	set( "object", ([
		"file9"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file7"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file1"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount4"  : 1,
		"amount10" : 1,
		"amount7"  : 1,
		"file6"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount6"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"file3"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount9"  : 1,
		"file10"   : "/open/magic-manor/obj/fire-color-ribbon",
		"file8"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file2"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount2"  : 1,
		"amount1"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount8"  : 1,
	]) );
	set( "owner", "ywarter" );
	set( "build", 10072 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room124.c",
		"east"      : "/open/clan/sky-wu-chi/room/room126",
	]) );
	set( "long", @LONG
这里的武器是属于比较平凡的,但也已经是非常不错的一些武器
如 狂龙翔天破(crazy dragon)寒冰(icefan)天诛笔(ten pen)
尚方宝剑(god sword)金钢指环(figring)穿龙剑(dragon sword)
雪影(iceblade)金鳞蟒邪(snake sword)日月神刀(sun-moon blade)
冰雪寒丝针(cold needle)

LONG);
	setup();
	replace_program(ROOM);
}
