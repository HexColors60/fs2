inherit ROOM;
void create() {
	set( "short", "法院" );
	set( "exits", ([
		"up"        : "/open/clan/hell/room/room128",
		"down"      : "/open/clan/hell/room/room129.c",
	]) );
	set( "long", @LONG
这里是冰判官审问机器人的法院，你一定是被人检举或是
行为太像机器人，才会来到这里，如果你答不出冰判官的三个
问题，可是会被冰判官踢回家睡觉唷! 好好回答(answer)吧。 

  专门对付笨蛋的审判官「$HIB$冷血无言$NOR$”冰判官(Judge ice)
$HIY$冰判官问道:「$HIW$十九减掉十七等于多少?$HIY$”$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
