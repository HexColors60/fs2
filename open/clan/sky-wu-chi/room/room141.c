inherit ROOM;
void create() {
	set( "short", "$HIY$【平南书院】 $CYN$大门$NOR$" );
	set( "owner", "lonsan" );
	set( "light_up", 1 );
	set( "object", ([
		"amount8"  : 1,
		"file7"    : "/open/killer/obj/k_ring",
		"amount6"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/gsword/obj/may_ring",
		"amount1"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/mogi/castle/obj/lochagem",
		"amount5"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/tendo/obj/luboot",
		"file6"    : "/open/mogi/dragon/obj/key",
		"file4"    : "/open/tendo/obj/chaosbelt",
		"file8"    : "/daemon/class/blademan/obj/shield",
		"amount4"  : 1,
		"file1"    : "/open/poison/obj/feather",
		"amount10" : 1,
		"file3"    : "/open/mogi/castle/obj/lochagem",
	]) );
	set( "build", 10738 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room140",
		"enter"     : "/open/clan/sky-wu-chi/room/room139",
	]) );
	set( "long", @LONG
在林荫密布的小道尽头，可以看到一间书院独自伫立在树海之中，四周一片宁
静祥和，只有偶尔传出细细的读书声。书院四周用云南大理石堆砌成白色矮墙，围
绕着整个书院，而在大门旁边有一座古色古香的凉亭，似乎经历过时代的陶冶。走
进大门仔细一瞧，可以发现大门是用高级的红桧木所制，十分坚固，门上雕刻的是
孔子跟其弟子上课的情景，在门上方有一个黑底金字的牌匾，上面写着

                *********************************
                *                               *       
                *          $HIY$平 南 书 院$NOR$          *
                *                               *
                *********************************

四个大字，笔法飞扬飘逸，字迹雄浑有力，看得出来是名家手笔。在门口旁边贴着
一张公告，【进入书院者，请将你随身武器放在旁边的架上】。
LONG);
	setup();
	replace_program(ROOM);
}
