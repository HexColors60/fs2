inherit ROOM;
void create() {
	set( "short", "$HIC$【内力装备专柜】$NOR$" );
	set( "owner", "peiyi" );
	set( "object", ([
		"file6"    : "/open/mon/obj/ghost-cloak",
		"file2"    : "/open/tendo/obj/chaosbelt",
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"amount3"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"file9"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount4"  : 1,
		"file3"    : "/open/wu/npc/obj/armband",
		"file4"    : "/open/mon/obj/ghost-legging",
		"file10"   : "/daemon/class/fighter/figring",
		"file1"    : "/daemon/class/blademan/obj/shield",
		"amount1"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/mon/obj/ghost-helmet",
		"file7"    : "/open/mogi/castle/obj/lochagem",
	]) );
	set( "build", 11054 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room226",
	]) );
	set( "long", @LONG
    你打开西边的小柜子，把头探了进去看看，里面是一整套加内力等
级的高级装备，包括有 :

   ( 1) 混沌腰带(chaos belt)
   ( 2) 罗刹女饰(gem)
   ( 3) 妖幻头带(ghost helmet)
   ( 4) 妖幻护膝(ghost legging)
   ( 5) 妖幻披掮(ghost cloak)
   ( 6) 狂龙翔天破(crazy dragon)
   ( 7) 夕霞红纱(sun_red_cloth)
   ( 8) 幸运草环(lucky grasslink)
   ( 9) 魔法盾(magic shield)
   (10) 阳炎臂环 (Sun Fire Armband)

这是小佩佩用来增加功力时穿的装备，是不会轻易借给别人的喔。
LONG);
	setup();
	replace_program(ROOM);
}
