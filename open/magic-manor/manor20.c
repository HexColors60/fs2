#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "左灵火舍");
	set ("long", @LONG
火舍中充满了一股奇异的灵气，灵气中隐隐的含着火的气息，在
火舍的里侧正上方一块匾额题着「左灵火舍”，而且还是庄主亲自题
字，足以显得对此舍的主人之重视，透过火舍窗户向外看过去可以隐
隐看到一个缭绕着漫天火焰的火灵塔。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"south"	: __DIR__"manor07",
	]));

	set("light_up", 1);

	setup();
}
