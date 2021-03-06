inherit ROOM;
void create() {
	set( "short", "$HIW$正$HIG$．$HIR$邪$HIG$．$HIB$道$NOR$" );
	set( "owner", "rings" );
	set( "item_desc", ([
		"words" : @ITEM
    
    [1;37m正    [1;31m邪    [1;34m两    [1;33,[1;33m不    [1;32m分[0m
      
ITEM,
	]) );
	set( "object", ([
		"file2"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount5"  : 1,
		"amount8"  : 1,
		"file6"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount3"  : 1,
		"file1"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount1"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/obj/evil-kill-claw",
		"file8"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file3"    : "/open/magic-manor/obj/maun-shadow-blade",
	]) );
	set( "build", 10049 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room232",
		"enter"     : "/open/clan/ou-cloud-club/room/room220.c",
		"up"        : "/open/clan/ou-cloud-club/room/room229",
	]) );
	set( "long", @LONG
沿着小径缓缓前进，来到了一间空间广阔的石室，光线
是从较为上层的石壁透光而来，仰头望去，有一座悬空的平
台，靠着十六条手腕般粗的铁链与周围的墙壁连结，铁链上
布满了数以万计的蜘蛛，平台上有一块小石碑，上面刻着几
个大字(words) ，石碑周围有几把兵器隐隐泛着金光。
  
LONG);
	setup();
	replace_program(ROOM);
}
