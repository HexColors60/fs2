inherit ROOM;
#include <ansi.h>

void create ()
{
	set("short",HIC"琰 扬 湖"NOR);
	set("long",@LONG
在一旁有许多贩卖着小吃的邪兽，你兴致勃勃的钱去看望，只见
上面放满了许多的蛊虫、腐肉，脸色一垮，赶紧的走回步道...
LONG);
	set("evil_area",1);
	set("no_transmit",1);
	set("exits",([
"south":__DIR__"a-12",
"north":__DIR__"a-10",
]));
	setup();
}

 