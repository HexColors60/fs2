#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "走道");
	set ("long", @LONG
一个简简单单的走道，可以通往水灵塔和各个灵阁，周围的景致
也很宜人，让你在这小小走道上稍微休息一下也是一个不错的想法。
北边是水灵道，你也可以感觉有阵阵的水气传向这里。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor21",
	"east"	: __DIR__"manor05",
	"west"	: __DIR__"manor03",
	]));

	set("light_up", 1);
	set("outdoors", "/open/magic-manor");

  setup();
}
