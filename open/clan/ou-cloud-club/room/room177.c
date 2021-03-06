inherit ROOM;
void create() {
	set( "short", "$HIY$Radiohead$NOR$" );
	set( "owner", "devil" );
	set( "light_up", 1 );
	set( "object", ([
		"amount5"  : 1,
		"amount2"  : 1,
		"amount7"  : 20,
		"file10"   : "/open/capital/guard/gring",
		"file3"    : "/obj/gift/xisuidan",
		"file5"    : "/obj/gift/xisuidan",
		"amount8"  : 8,
		"amount10" : 1,
		"file9"    : "/open/killer/headkill/obj/w_dag",
		"amount6"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/killer/headkill/obj/f_dag",
		"file4"    : "/open/sky/obj8/summer_wind",
		"file2"    : "/obj/gift/xisuidan",
		"amount4"  : 1,
		"file6"    : "/open/main/obj/m_cloak",
		"file7"    : "/open/doctor/pill/gnd_pill",
		"file8"    : "/open/fire-hole/obj/p-pill",
		"amount9"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 10024 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room251",
		"out"       : "/open/clan/ou-cloud-club/room/room139.c",
		"up"        : "/open/clan/ou-cloud-club/room/room141.c",
	]) );
	set( "long", @LONG

没有传统媒体的过度包装，电台司令以其近乎「艺术品”的后摇滚
实验乐风，直接证明他们身为「九０年代另类摇滚代言人”的创作
实力其实，在制作Kid A 的同时，电台司令便已谱写了二十三首作
品，其中已有十首收录在Kid A 中。时隔半年有余，他们又从其中
择选十一首作品，发表了第五张专辑Amnesiac。虽是同时期的创作
，Amnesiac却与Kid A融入大量电气声响、鼓击的后摇滚格调不同。 

LONG);
	setup();
	replace_program(ROOM);
}
