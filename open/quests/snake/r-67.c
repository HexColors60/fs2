inherit ROOM;

void create()
{
	set("short","蛇寨 副蛇座");
	set("long",@LONG
在你眼前有一座巨大的蛇雕座椅，十分的尊贵华丽，每片蛇鳞片
都是用价值不斐的翡翠作成的，蛇眼是有着鲜血般红焰的红宝石所制
成的，座椅是雪片白般的大理石，极度奢侈的一个蛇型座椅。
LONG);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/liu_snake":1,
]));
	set("exits",([
"south":__DIR__"r-66",
"north":__DIR__"r-68",
]));
	setup();
}
