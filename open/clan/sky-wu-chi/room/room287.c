inherit ROOM;
void create() {
	set( "short", "小花园" );
	set( "owner", "bbsman" );
	set( "light_up", 1 );
	set( "object", ([
		"file2"    : "/open/gblade/obj/dragon_book",
		"amount7"  : 1,
		"amount9"  : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"file4"    : "/daemon/class/blademan/obj/shield",
		"amount6"  : 1,
		"file3"    : "/daemon/class/blademan/obj/shield",
		"amount5"  : 1,
		"file7"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount8"  : 1,
		"file8"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount1"  : 1,
		"file6"    : "/open/quests/snake/npc/obj/snake_gem",
		"file5"    : "/open/killer/obj/kill_yar_head",
		"file1"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount4"  : 1,
		"file9"    : "/open/killer/obj/k_ring",
	]) );
	set( "build", 10361 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room122",
	]) );
	set( "long", @LONG
这里是一个小花园种满了鲜花和树木，充满了芬芳的味道令人不经想
多呆这里一会，中间还有个小水塘里面还有几只天鹅正在游水令人赏心悦
目，这里的主人看起来很爱这个地方，把它们照顾的很好很漂亮，阳光透
过叶缝洒在你的身上暖洋洋的不禁让你想打个盹！
LONG);
	setup();
	replace_program(ROOM);
}
