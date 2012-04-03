#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", HIR"火灵塔"NOR);
	set ("long", @LONG
火灵塔的周围遍满了火焰的包围，炽热的火气不时的向你这边袭
来，若非功力深厚的人，将承受不住这样大的火气侵袭，此塔中布满
了火焰，若不能寻找到一个克制火的宝物，将有可能在里面被火焰活
活的给烧死。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"south"	: __DIR__"manor22",
	"enter"	: __DIR__"fire/fire01",
	]));

	set("outdoors", "/open/magic-manor");

	setup();
}
