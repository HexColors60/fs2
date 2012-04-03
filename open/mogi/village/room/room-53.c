//room:/u/e/eva/village/room/room-53.c        made by eva
#include <room.h>
#include <ansi.h>
#include <village.h>

inherit ROOM;

void create()
{
    set("short","魔界村道具店");
	set( "build", 4534 );
    set("long","
    这里是魔界村中的道具店, 店中摆\了许多奇奇怪怪的器具, 大概
是用来处理药材的吧? 后面的橱柜中摆\了瓶瓶罐罐的药水, 不过你不
知道有啥作用罢了.\n\n");
    set("exits",([
        "out" : __DIR__"room-49",
        ]));
    set("objects",([
        V_NPC"i_boss" : 1 ,
        ]));
    set("no_fight",1);
    set("no_magic",1);
    set("light_up",1);
    set("no_auc",1);
    set("no_transmit",1);
    set("evil",1);
    setup();
}
