#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "走道");
	set ("long", @LONG
一个简简单单的走道，可以通往火灵塔和各个灵阁，周围的景致
也很宜人，让你在这小小走道上稍微休息一下也是一个不错的想法。
北边是火灵道，你也可以感觉有阵阵的火之气息传向这里。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor22",
	"east"	: __DIR__"manor07",
	"west"	: __DIR__"manor09",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
