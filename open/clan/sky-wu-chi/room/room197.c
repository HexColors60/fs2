inherit ROOM;
void create() {
	set( "short", "$HIY$【平南书院】 $HIG$中庭$NOR$" );
	set( "owner", "lonsan" );
	set( "object", ([
		"file3"    : "/open/wu/npc/obj/armband",
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
		"file7"    : "/open/ping/obj/cloud",
		"amount9"  : 1,
		"file2"    : "/open/magic-manor/obj/hwa-je-icer",
		"file9"    : "/open/mon/obj/ghost-claw",
		"amount8"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"amount6"  : 1,
		"file8"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount10" : 1,
		"amount1"  : 1,
		"file6"    : "/open/ping/questsfan/obj/key",
		"amount7"  : 1,
		"file10"   : "/open/magic-manor/obj/maun-shadow-blade",
		"file1"    : "/open/magic-manor/obj/magic-sign",
		"amount3"  : 1,
	]) );
	set( "build", 10370 );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room199",
		"east"      : "/open/clan/sky-wu-chi/room/room198",
		"south"     : "/open/clan/sky-wu-chi/room/room139.c",
	]) );
	set( "long", @LONG
经过一道拱门，你来到了平南书院的中庭，这里是一片宽阔的地方，四周以围
墙跟其他区域隔开，连接四面的区域都有一个拱型门作为通道，在东南方有一个小
池子，池子中央有一个凉亭，名曰：〔静心亭〕，有一座九曲桥连接到那儿。在东
边是一片银杏林，林内饲养着许多奇珍异兽，性情都是十分温驯，还有一座草芦座
落在林中央。在中庭的中央是一片大广场，常常会有许多的活动是在这里举行，西
北有一座假山，上面还有一个小瀑布，西南方是一排排的公布栏，上面张贴的有各
式各样的海报或是一些重要的命令。
LONG);
	setup();
	replace_program(ROOM);
}
