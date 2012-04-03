inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","蛇寨 大门");
	set("long","这里是蛇寨的大门，门口处长满了许多的藤蔓，若不仔细搜查，
还真的不容易发现大门的位置，不过在这个山寨的上方，有两个石制
的蛇头就显的非常的明显，仿佛是在警告着来者，请勿轻易入洞，免
得惨招毒蛇之吻...

			"+HIG+"<蛇寨>\n"NOR);
	set("exits",([
"west":"/open/main/room/s22",
]));
	setup();
}

void init()
{
add_action("do_enter","enter");
}

int do_enter()
{
object me = this_player();

	message_vision("$N拨开藤蔓，推开大门后，走了进去。\n",me);
	me->move(__DIR__"r-02");
return 1;
}