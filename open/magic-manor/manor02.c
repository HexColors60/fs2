#include <ansi.h>
#include <room.h>

inherit ROOM;

void create ()
{
	set ("short", "穿堂");
	set ("long", @LONG
藉由穿堂往北方可以通达聚灵山庄的正殿，西边可以通达聚灵山
庄的各个舍室，而东边的方向则可以通往各个阁室，是一个极为重要
的穿堂，因此守卫也比较森严些。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor01",
	"south"	: __DIR__"manor72",
	"east"	: __DIR__"manor03",
	"west"	: __DIR__"manor07",
	]));

	set("item_desc", ([ /* sizeof() == 1 */
	"south" : (: look_door,     "south" :),
	]));

	create_door("south",HIR"鸿元聚灵门"NOR,"north",DOOR_CLOSED);
	set("light_up", 1);

	setup();
	replace_program(ROOM);

}
