#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "走廊");
	set ("long", @LONG
灵阁外的走廊，南北各通往一间灵阁，南边的是天灵阁，北边的
是齐灵阁，再往东边可以通往另一段走廊，走廊两旁的景物朴实简单
却又不失高雅。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor18",
	"south"	: __DIR__"manor15",
	"east"	: __DIR__"manor06",
	"west"	: __DIR__"manor04",
	]));

	set("light_up", 1);

	setup();
}
