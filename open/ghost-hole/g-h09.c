#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",BLU"死灵幽谷"NOR);
set("long",@LONG
地上堆满了许多的食物与茶, 这里可能是居住在
这里人的食物储藏室, 这里的空气似乎比其他的地方
还来的冷, 难怪会被选作储藏食物的地方...
LONG);
set("outside",1);
set("exits",([
"east":__DIR__"g-h08",
]));
set("objects",([
"/obj/example/chicken_leg":1,
"/open/capital/obj/tea":1,
]));
set("no_transmit",1);
setup();
}
