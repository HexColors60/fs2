inherit ROOM;
void create() {
	set( "short", "赤龙居" );
	set( "owner", "xman" );
	set( "object", ([
		"amount5"  : 1,
		"file6"    : "/open/fire-hole/obj/r-pill",
		"amount6"  : 10,
		"file9"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount8"  : 1,
		"file2"    : "/open/mogi/castle/obj/blood-water",
		"amount2"  : 1,
		"amount9"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/killer/headkill/obj/world_dag",
		"file3"    : "/open/magic-manor/obj/evil-kill-claw",
		"file7"    : "/open/doctor/pill/gnd_pill",
		"file1"    : "/open/fire-hole/obj/w-pill",
		"amount10" : 1,
		"file8"    : "/open/gblade/obj/dragon_book",
		"amount1"  : 4,
		"amount7"  : 50,
		"file5"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file10"   : "/open/mon/obj/ghost-legging",
		"amount4"  : 1,
	]) );
	set( "build", 10225 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room296",
		"west"      : "/open/clan/sky-wu-chi/room/room94",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG
假如真再有约会
 
主 唱:蒋嘉莹
 
人清醒 难感性 迷失方能找到期待爱情
梦中见 亦高兴 能将心灵希冀尽说明

谁决定 人本性 或许生命中有埋没姓名
纯真爱 难记认 人间本来应该是有情

望这不再熟悉破落故城 何以变了这样宁静
长街失去欢欣笑声 留下我孤单的一个生命
凝望这风雪未知那日会停 来世你我要是重认
能否找到彼此背影 假如全无凭无证* 

Repeat *...* 

愿谅我当天不懂得珍惜 只知任性
坏事情 唯愿你此刻可于虚空中将心聆听
将来若 真的再有个约会会完成
真的会再有这样深情 我以天为证
跟你带领 我以天为证 请你带领 
 

LONG);
	setup();
	replace_program(ROOM);
}
