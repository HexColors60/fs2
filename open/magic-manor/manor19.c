#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "右灵水阁");
	set ("long", @LONG
水阁中充满了一股奇异的灵气，灵气中隐隐的含着水的气息，在
水阁的里侧正上方一块匾额题着「右灵水阁”，而且还是庄主亲自题
字，足以显得对此阁的主人之重视，透过水阁窗户向外看过去可以隐
隐看到一个缭绕着漫天水气的水灵塔。
LONG);

	set("no_auc", 1);
	set("no_transmit", 1);

	set("exits", ([ /* sizeof() == 3 */
	"south"	: __DIR__"manor03",
	]));

	set("light_up", 1);

	setup();
}
