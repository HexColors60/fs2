// Room: /u/c/chhu/workroom.c
#include "../cold.h"

inherit ROOM;

void create()
{
	set("short","宝珍神宫东侧侧厅");
	set("long", @LONG
这里是东侧的侧厅，乍看之下并无什么特殊之处，只是在北面的
墙壁上挂着一幅壁画，上面画着一个仙女，像是嫦娥奔月似的，另人
疑惑的是这里为何有这么一幅画，是否宝珍神宫里隐藏着什么特殊的
秘密 ?

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"west":COLD_ROOM"in1",
]));
	set("objects",([
	]));
	setup();
	replace_program(ROOM);
}
