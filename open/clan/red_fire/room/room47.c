inherit ROOM;
void create() {
	set( "short", "大厅" );
	set( "owner", "jenny" );
	set( "object", ([
		"amount7"  : 1,
		"file9"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"amount10" : 1,
		"amount4"  : 1,
		"amount8"  : 1,
		"file2"    : "/open/ping/obj/cloud_fan",
		"file1"    : "/daemon/class/fighter/figring",
		"file7"    : "/open/wu/npc/obj/armband",
		"file8"    : "/open/ping/questsfan/obj/diamond_legging",
		"amount3"  : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/ping/questsfan/obj/diamond_skirt",
		"file6"    : "/open/scholar/obj/icefan",
		"amount5"  : 1,
		"amount9"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"file4"    : "/daemon/class/blademan/obj/shield",
		"file10"   : "/open/ping/obj/gold_hand",
	]) );
	set( "build", 10041 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/red_fire/room/room57",
		"east"      : "/open/clan/red_fire/room/room83.c",
	]) );
	set( "long", @LONG

你踏进了一间很豪华的大厅，地板上铺着深红色的地毯，客厅的角落
有一个火炉，熊熊的火焰在火炉中燃烧，房间中间摆了两具大沙发，
在其中一面墙上有一幅轻风的全家福照片，在火炉的斜前方是一个古
老的书架，上面放了几本神秘的古书。


LONG);
	setup();
	replace_program(ROOM);
}
