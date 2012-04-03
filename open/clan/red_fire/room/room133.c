inherit ROOM;
void create() {
	set( "short", "$HIM$肉脚$HIW$的$HIR$杀手$HIC$居$NOR$" );
	set( "object", ([
		"amount4"  : 40000,
		"file4"    : "/open/killer/obj/hate_knife",
		"file3"    : "/open/killer/obj/hate_knife",
		"amount5"  : 50000,
		"file2"    : "/open/killer/obj/hate_knife",
		"amount6"  : 50000,
		"amount2"  : 30000,
		"amount3"  : 20000,
		"file6"    : "/open/killer/obj/hate_knife",
		"file5"    : "/open/killer/obj/hate_knife",
	]) );
	set( "owner", "pipi" );
	set( "build", 10020 );
	set( "exits", ([
		"east"      : "/open/clan/red_fire/room/room85",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

一进到这里，环顾四周，上竟挂满了一颗颗的$HIR$人头$NOR$，你仔细一看壁上的$HIR$人头$NOR$
在$HIC$武林$NOR$中都是赫赫有名的人物。但心中的$HIC$震惊$NOR$却扺不过对此地主人的好奇究
竟是何方人物能将各方高手的$HIR$人头$NOR$取下来当$HIY$壁饰$NOR$。往前一走，忽然一阵带着
强大$HIM$压$HIY$迫$HIC$感$NOR$的气息向你$HIM$侵袭$NOR$过来，压迫的来源竟是来自中央的人所散发出来
的，难道他就是此间的主人。看到这样的情况以及$HIW$壁上$NOR$的$HIR$人头$NOR$你唯一的想法
就是快跑......。


LONG);
	setup();
	replace_program(ROOM);
}
