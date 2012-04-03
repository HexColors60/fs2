// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","监牢地道");
        set("long", @LONG
走到这就是地道的尽头了，这除了左右各有一间牢房外就没有别
的东西。但尽头的墙(wall)和别的地方的墙颜色有点不同，你在想--
可能是因为地道的关系吧!!且左右的火把闪烁不定使你更加确定你的
推测。
LONG);
set("exits", ([
	"north":__DIR__"r73",
	"west":__DIR__"r77",
	"east":__DIR__"r80",
]));
  setup();
}
void init()
{
        add_action("do_push","push");
}

int do_push(string str)
{
        object who;
        who = this_player();

        if(str!="wall"){return 0;}
        tell_object(who,"你轻轻的推了一下墙，但墙却快速的转了一圈，也连带把你转"+"了进去。\n");
        who->move("/open/tendo/room/r81");
        tell_room(this_object(),"你看到尽头的墙被"+who->query("name")+"一推之下"
				+"转动了一圈，而"+who->query("name")+"也被墙给"+
				"转了进去。\n");
        return 1;
}
