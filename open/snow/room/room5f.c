#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create()
{
          set("short","八卦迷宫阵");
        set("valid_startroom", 1);
          set("long","你已经走入八卦迷宫阵，只见四周都是岩石，以及一些困死在此的人的骸骨，在此你已无法辨明方向。\n");
        set("exits", ([
		"north":__DIR__"room5",
		"south":__DIR__"room5",
		"west":__DIR__"room5c",
			"east":__DIR__"room5g",
        ]) );
	set("objects",([SNOW_NPC"ghost":1]));
       set("no_fight",1);
        setup();
}
