#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "土灵道");
	set ("long", @LONG
一条通往土灵塔必需要经过的道路，土灵塔那里传来的土之气息
已经愈来愈浓厚，若非有一番修为的人来到此，也许会抵受不住那飞
沙走石的猛烈侵袭。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"north"	: __DIR__"manor65",
	"south"	: __DIR__"manor59",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
