inherit ROOM;
void create() {
	set( "short", "$HIC$堕$NOR$$HIG$落$NOR$$HIY$天$NOR$$HIR$使$NOR$的$HIM$内习调养室$NOR$" );
	set( "build", 12240 );
	set( "owner", "fsfs" );
	set( "exits", ([
		"west"      : "/open/clan/red_fire/room/room109",
	]) );
	set( "long", @LONG

这里是$HIC$堕$NOR$$HIG$落$NOR$$HIY$天$NOR$$HIR$使$NOR$的$HIM$内习调养室$NOR$，正中央有个座位，上面
正散发出阵阵的$HIC$寒气$NOR$，你虽离它三尺却也感到有股阵阵
阴气向你侵袭过来。传说中，在修练内息时若有$HIC$寒气宇
寒装$NOR$可帮助锻炼内息，你往左右一看居然有一套服装散
发着$HIC$寒意$NOR$，原来$HIC$堕$NOR$$HIG$落$NOR$$HIY$天$NOR$$HIR$使$NOR$他连此等寒装都已找到了。


LONG);
	setup();
	replace_program(ROOM);
}
