inherit ROOM;
void create() {
	set( "short", "$HIC$风剑$HIG$的$HIW$房间$NOR$" );
	set( "owner", "waysword" );
	set( "object", ([
		"file1"    : "/open/mon/obj/ghost-claw",
		"file4"    : "/open/capital/obj/4-4",
		"amount5"  : 1,
		"file3"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount6"  : 1,
		"amount4"  : 1,
		"file5"    : "/open/mogi/castle/obj/lochagem",
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"amount1"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10044 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/red_fire/room/room84",
	]) );
	set( "long", @LONG

你一进门就看到大大的$HIR$对联$NOR$

$HIY$上联$NOR$--$HIC$百战沙场$HIM$ 傲群雄$NOR$

$HIY$下联$NOR$--$HIC$仗剑天下$HIM$ 我独尊$NOR$

$HIY$横批$NOR$--$HIC$爱剑痴狂$HIM$ 第一剑$NOR$

这也正是$HIC$风剑$NOR$的写照，而你所在的这个房间往
窗外看出去正巧是一片$HIB$云海$NOR$，$HIC$世$HIY$间$HIR$红$HIM$尘$NOR$尽收眼
底，让你不禁想说一句「好美”，而这间房间
也是$HIC$风剑$NOR$修练$HIY$内力$NOR$的房间，简单朴素，就像$HIC$风
剑$NOR$的为人一样。


LONG);
	setup();
	replace_program(ROOM);
}
