inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",BBLU+YEL"震邪道"NOR);
	set("long",@LONG
再一个闪耀着金黄色光芒的四方形空间内, 有一个黄金守卫正在
站立在一道雕硕精美的黄金门前, 黄金守卫的双目直盯着所有踏入这
房间内的人, 当然, 也包括你在内...
LONG);
	set("objects",([
__DIR__"npc/golden_guard":1,
]));
	set("no_transmit",1);
	set("exits",([
"west":__DIR__"e04",
]));
	setup();
}

