#include <ansi.h>
inherit ROOM;
void create ()
{
        set("short",YEL"幽冥道"NOR"小村");
        set("long",@LONG
南边有一个草造的茅草屋, 听说里面住着一个
通晓幽冥界的智者, 也许你应该先去拜访他一下, 
或许对你打败死灵骨魔会有所帮助...
LONG);
        set("exits",([
        "enter":__DIR__"g-r08",
        "north":__DIR__"g-r04",
        ]));
        set("no_transmit",1);
        setup();
}
