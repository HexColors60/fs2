inherit ROOM;
void create() {
	set( "short", "天灵丹药柜" );
	set( "object", ([
		"amount10" : 1,
		"file10"   : "/daemon/class/blademan/obj/ublade",
		"file2"    : "/open/magic-manor/obj/master_snake_head",
		"amount7"  : 1,
		"amount9"  : 1,
		"amount3"  : 10,
		"amount2"  : 1,
		"file4"    : "/open/doctor/item/sky_item",
		"amount6"  : 17,
		"file3"    : "/open/doctor/pill/gnd_pill",
		"amount5"  : 14,
		"file7"    : "/open/quests/snake/npc/obj/snake_gem",
		"amount8"  : 1,
		"file8"    : "/open/quests/snake/npc/obj/helmet",
		"amount1"  : 1,
		"file6"    : "/open/doctor/item/ground_item",
		"file5"    : "/open/doctor/item/human_item",
		"amount4"  : 15,
		"file1"    : "/open/magic-manor/obj/master_snake_head",
		"file9"    : "/daemon/class/blademan/obj/shield",
	]) );
	set( "build", 10024 );
	set( "owner", "amei" );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room293",
	]) );
	set( "long", @LONG
这里是AMEI摆三种救命丹药之中的天灵丹的地方，他的最大功效
就是能恢复所有的状态，不过要是碰上一些奇奇怪怪的状态他
就没办法了，这是他唯一的缺点但是自从长沙镇的超级仙丹停售时
他却变成了最抢手的丹药O，假如你冻伤或灼伤想要赶快好记得来
跟AMEI拿点天灵丹去吃吧！
LONG);
	setup();
	replace_program(ROOM);
}
