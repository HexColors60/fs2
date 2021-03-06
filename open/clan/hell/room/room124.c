inherit ROOM;
void create() {
	set( "short", "小笨蛋的储藏室" );
	set( "owner", "acelan" );
	set( "object", ([
		"amount2"  : 45,
		"amount4"  : 3,
		"file1"    : "/obj/gift/xisuidan",
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"file4"    : "/open/mogi/village/obj/f_pill_m",
		"amount1"  : 1,
		"amount3"  : 10,
		"file2"    : "/open/ping/obj/poison_pill",
	]) );
	set( "build", 10299 );
	set( "item_desc", ([
		"script" : @ITEM
session {fs} {140.115.72.117 4000}
act {请输入您的英文名字} {acelan}
act {请输入密码} {xxx}
speedwalk

ticksize 5
tickoff

gag {你坐下来运气}
alias {f %1} {fight %1;mk}
alias {k %1} {kill %1;mk}
alias {ee} {19 ex 10;ec}
alias {eee} {ex 600;ec 3}
alias {eeee} {ex 1500;ec 5}
alias {rrr} {er;eg;ec;3 eee}
act {似乎内力修为已经遇到了瓶颈} {tickoff}
act {惨遭灭顶,但你也支持不住了。} {boss}
act {^TICK!!!} {ee}
alias {tower} {rn;set wimpy 0;  act {万蟋椰漱F。} {kill ghost;mk};act {九节尸死了。} {kill ghost;mk};act {鬼死了。} {kill ghost;mk};act {恶魂暴鬼(Ghost)} {k ghost};act {怒马疯鬼(Crazy ghost)} {k ghost};act {万蟋□Ghost)} {k ghost};act {九节尸(Nine ghost)} {k ghost}}

alias {rn} {alias {f %1} {fight %1;rain};alias {k %1} {kill %1;rain}}
alias {manakee} {alias {f %1} {fight %1;mk};alias {k %1} {kill %1;mk}}
alias {weapon} {re;d;8 e;2 n;2 e;pull button;n;enter;n;u;n;e;search;d}

alias {expup} {action {护法死了} {get gold from corpse;k fa}; action {你想杀死谁} {tell kiroro okk!};action {冲出两位护法} {k fa}}
alias {stopexp} {unact {护法死了};unact {你想杀死谁};unact {冲出两位护法}}

alias {killer} {re;d;8 e;2 n;2 e;pull button;n;enter}
alias {killerpill} {out;s;2 w;n;get rock;s;w;puton rock;tree;search;3 e;n;enter;4 n;wash;wash;3 s;2 w;give woman herb}
ITEM,
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room125",
	]) );
	set( "long", @LONG
这里塞满了小笨蛋弃置的东西，一个一个的都用蛋壳装好，整整
齐齐的排列在墙边，最特别的是在墙上钉了一张纸，上面写着小笨蛋
用来玩 FS 的 tintin 的 (script) ，这张 script 的内容经常变动
，所以会不定时更新。
LONG);
	setup();
	replace_program(ROOM);
}
