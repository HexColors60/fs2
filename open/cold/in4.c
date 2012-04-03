// Room: /u/c/chhu/workroom.c
#include "../cold.h"

inherit ROOM;

void create()
{
	set("short","宝珍神宫后厅");
	set("long", @LONG
这里是宝珍神宫的后厅，真在宝珍神宫里有分大厅、内厅，侧厅，
及后厅，而这个后厅是宫主平时养神、修心之处，每当宫主处理完一些
内务之后，常常会在此休息，而在厅内则有舞群献舞，歌者奏乐，基本
上，寒谷一派的门人都十分清雅，连掌门也不例外。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"south":COLD_ROOM"in1",
	"north":COLD_ROOM"in5",
]));
	set("objects",([
	]));
	setup();
	replace_program(ROOM);
}
