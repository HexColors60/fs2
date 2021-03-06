inherit ROOM;
void create() {
	set( "short", "$HIY$【平南书院】 $HIM$天籁厅$NOR$" );
	set( "owner", "lonsan" );
	set( "object", ([
		"file10"   : "/open/ping/questsfan/obj/diamond_legging",
		"amount1"  : 1,
		"amount4"  : 1,
		"file8"    : "/open/ping/questsfan/obj/diamond_hands",
		"file5"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"amount8"  : 1,
		"file1"    : "/open/ping/obj/cloud_fan",
		"amount3"  : 1,
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"file2"    : "/open/ping/questsfan/obj/diamond_armor",
		"amount9"  : 1,
		"file6"    : "/open/ping/questsfan/obj/diamond_boots",
		"amount5"  : 1,
		"amount10" : 1,
		"file4"    : "/open/ping/questsfan/obj/diamond_skirt",
		"file3"    : "/open/ping/questsfan/obj/diamond_cloak",
		"amount6"  : 1,
		"amount7"  : 1,
		"amount2"  : 1,
		"file7"    : "/open/ping/questsfan/obj/diamond_belt",
	]) );
	set( "build", 10066 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room197",
	]) );
	set( "long", @LONG
天籁厅顾名思义就是能欣赏到天籁之音的地方，这里也是平南书院教授‘乐’
课程的所在。天籁厅大致上可以区分成三个部分，在南边有十乘十个座位椅子，而
中间属于表演枱部分，平时老师授课也是在表演枱里教导学生们乐器的使用技巧及
乐理，较北边的地方有一个落地式大屏风区隔开来，里面放的是各式各样的乐器，
学生们也常常把自己的东西放在这里，此处亦严禁外人进入，而门口的左右两侧，
是属于休息区的部分，但是右手边的休息区比较没有人会进去，那里是学生们平日
练习乐器时常常待的地方。

LONG);
	setup();
	replace_program(ROOM);
}
