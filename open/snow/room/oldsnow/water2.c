#include <room.h>

inherit ROOM;
void do_west();
void create()
{
            set("short","雪泉");
      set("long",@LONG
这里是雪苍山的山脚，往西通往雪泉，相传雪泉中的雪泉圣水
有神奇的魔力，但是在雪泉中有传说中的守护圣兽把守着，而
且圣水的位置到底在那，也是一个问题，不少英雄豪杰，进入
雪泉都无功而返。
LONG);
        set("exits", ([
		"east":__DIR__"room3",
		"west":__DIR__"water",
        ]) );
	set("light_up",1);
        setup();
}
