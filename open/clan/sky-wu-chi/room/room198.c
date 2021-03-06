inherit ROOM;
void create() {
	set( "short", "$HIY$【平南书院】 $HIW$杏林医庐$NOR$" );
	set( "owner", "lonsan" );
	set( "light_up", 1 );
	set( "object", ([
		"file4"    : "/open/fire-hole/obj/p-pill",
		"amount10" : 1,
		"file10"   : "/open/quests/snake/npc/obj/snake_gem",
		"amount1"  : 94,
		"amount2"  : 23,
		"amount5"  : 36,
		"amount9"  : 100,
		"amount6"  : 86,
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"file8"    : "/open/fire-hole/obj/b-pill",
		"file9"    : "/open/fire-hole/obj/r-pill",
		"file7"    : "/open/fire-hole/obj/y-pill",
		"file5"    : "/open/mogi/castle/obj/sspill",
		"file1"    : "/open/fire-hole/obj/w-pill",
		"amount8"  : 110,
		"amount4"  : 52,
		"file3"    : "/open/fire-hole/obj/g-pill",
		"file2"    : "/open/fire-hole/obj/k-pill",
		"amount7"  : 2462,
		"amount3"  : 2646,
	]) );
	set( "build", 10059 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room197",
	]) );
	set( "long", @LONG

                *********************************       
                *                               *
                *        $HIY$医 者 父 母 心$NOR$         *
                *                               *
                *********************************

一走进医庐，就可以看到斗大的几个烫金字，这是当代最伟大的名医--华陀，
在莅临过此处后留下的真迹，也是杏林医庐多年来行医的宗旨，无论是黑道白道，
王公贵族或者平民百姓，只要求医至此，必定竭尽心力救治，是以多年来此处隐然
已经是武林中的非战之区，总使两人仇深似海，在此处相遇也必定不会兵刃相向，
总是相约到外面解决。医庐里面十分简朴，除了一个宽阔的大厅，有一张看诊桌及
两张椅子外，也没有别的东西，在旁边有一扇门，里面只有医庐里的人可以进去，
而四周墙壁上有着一排排的凹槽，上面放的无非是药草灵丹等药及药引，还有一些
可以提供阅读的一些佛经。
LONG);
	setup();
	replace_program(ROOM);
}
