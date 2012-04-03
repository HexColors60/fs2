inherit ROOM;
void create() {
	set( "short", "路标区" );
	set( "object", ([
		"file5"    : "/open/mon/obj/ghost-cloak",
		"amount8"  : 1,
		"amount1"  : 27,
		"file8"    : "/daemon/class/blademan/obj/ublade",
		"amount2"  : 1,
		"amount5"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/gsword/obj/ring-1",
		"amount6"  : 1,
		"file7"    : "/open/mon/obj/ghost-legging",
		"file1"    : "/open/ping/obj/poison_pill",
		"amount7"  : 1,
		"file6"    : "/open/mon/obj/ghost-helmet",
		"amount4"  : 1,
		"file2"    : "/daemon/class/bonze/puty_pullium",
		"file4"    : "/open/scholar/obj/icefan",
	]) );
	set( "owner", "woan" );
	set( "build", 11454 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room123.c",
		"west"      : "/open/clan/13_luck/room/room159",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
    
    进来后..你看到一个标示牌..上面写着
      
       想听woan [0;1;31m□[1mt[1m□[1m□[1m□[1m|[0m的请往西
      
       想看woan [0;1;33m□[1mm[1m□[1m\[1m□[1m□[0m的请网东 
此时你想.woan身为一个[0;1;5;36m□[1;5mT[1;5m□[1;5mM[1;5m□[1;5my[1;5;32m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5m□[1;5mH[0m
有[0;1;33m□[1mm[1m□[1m\[1m□[1m□[0m不足为奇..但..一个刀客竟会开
[0;1;31m□[1mt[1m□[1m□[1m□[1m|[0m...你也觉的.不可相信.但.一条条
[0;1;34m□[1m□[1m□[1m□[0m的歌曲打乱了你的思绪..而你所不相
信的事.却一一的变事实了.而你只想做一
件事.就是过去听好听的歌曲.


LONG);
	setup();
	replace_program(ROOM);
}
