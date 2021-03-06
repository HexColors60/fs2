// Room: /u/c/chhu/workroom.c
#include "../cold.h"

inherit ROOM;

void create()
{
	set("short","宝珍神宫大殿");
	set("long", @LONG
这里是寒谷一派的根据地，宝珍神宫是寒谷弟子世代居住的地方，
在大厅上，有一张用雪狼皮铺着的宝座，而四周装饰却是十分的单调，
格外显示出寒谷的冷清，然而在宝座之上有一月形标志，是寒谷一派的
象征，相传着，寒谷派的掌门人每天都要向只月形标志致敬，以表示对
前代师祖的尊敬。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"out":COLD_ROOM"home1",
	"north":COLD_ROOM"in1",
]));
	set("objects",([
	COLD_NPC"master":1,
	]));
	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}
