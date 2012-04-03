#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
          object ob;
           ob=this_player();
          set("short","四象阵阵眼");
          set("long",@LONG

你已经走入五行八卦阵的四象阵中，只见四周都是岩石，以及一
些困死在此的人的骸骨，在此你已无法辨明方向。腐烂的恶臭更是令
你无法忍受。再加上地面上都是烂泥，更是难走，脚上七高八低，望
出来黑漆一团，令人觉得一阴森恐怖。这里就是四象阵的阵眼，从这
里就可以离开四象阵了。\n");
LONG);
        set("exits", ([
	"north":__DIR__"room2",
	"south":__DIR__"room2b",
	"west":__DIR__"room2c",
	"east":__DIR__"room2b",
        ]) );
	set("objects",([
]));
        set("no_transmit",1);
          setup();
}
void init()
{
	add_action("do_search","search");
}
int do_search(string str)
{
	if(str!="eye") return 0;
	message_vision(
	"[1;37m$N从这里找了找，突然触碰了岩石，使阵眼打了开来。[0m\n",this_player());
	set("exits",([
	"north":__DIR__"room2",
	"south":__DIR__"room2b",
	"east":__DIR__"room2b",
	"west":__DIR__"room2c",
	"out":__DIR__"tower2-1",
	]));
	return 1;
}


