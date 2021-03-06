inherit ROOM;
void create() {
	set( "short", "miffy 大楼2-1" );
	set( "object", ([
		"amount10" : 1,
		"amount3"  : 1,
		"file5"    : "/open/firedancer/npc/eq/r_cape",
		"amount9"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/firedancer/npc/eq/r_hands",
		"amount7"  : 1,
		"file4"    : "/open/firedancer/npc/eq/r_cloth",
		"file7"    : "/open/firedancer/npc/eq/r_belt",
		"amount1"  : 1,
		"file10"   : "/open/firedancer/npc/eq/r_leg",
		"amount4"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/firedancer/npc/eq/r_boots",
		"file1"    : "/open/firedancer/npc/eq/r_head",
		"file3"    : "/open/firedancer/npc/eq/r_finger",
		"file9"    : "/open/firedancer/npc/eq/r_neck",
		"file8"    : "/open/firedancer/npc/eq/r_armbands",
		"amount6"  : 1,
		"amount5"  : 1,
	]) );
	set( "owner", "miffy" );
	set( "build", 14118 );
	set( "light_up", 1 );
	set( "exits", ([
		"southwest" : "/open/clan/sky-wu-chi/room/room329",
		"east"      : "/open/clan/sky-wu-chi/room/room322.c",
		"north"     : "/open/clan/sky-wu-chi/room/room325.c",
		"south"     : "/open/clan/sky-wu-chi/room/room324.c",
		"southeast" : "/open/clan/sky-wu-chi/room/room328.c",
		"northwest" : "/open/clan/sky-wu-chi/room/room326.c",
		"west"      : "/open/clan/sky-wu-chi/room/room323.c",
		"down"      : "/open/clan/sky-wu-chi/room/room318.c",
		"northeast" : "/open/clan/sky-wu-chi/room/room327.c",
	]) );
	set( "long", @LONG
这里是miffy 的一些wp 分类房,你可以看到以这里为中心有分为东西南北四房
而东西南北四房分别为东房杀意锥,西房千古恨,南房灭神匕,北房绝世匕
而从东西南北四房在延伸出去的有西北房为杂物房,东北房为丹药房
西南房杂器房,东南房为救神神丹房,等等总类共分为八大房
所以第二层乃是miffy 房的重点房...也禁止一些人物的禁入..这是为了安全起见
LONG);
	setup();
	replace_program(ROOM);
}
