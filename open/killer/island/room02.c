#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",HIW"走道"NOR);
set("long",@LONG
地上到处都堆满了武器、防具与....骨骸，看来这里是放兵器的地方，你不由
得的怀疑起来，一艘普通的船怎么可能会放置如此大量的武器呢？难道是做武器买
卖的商船吗？但是由武器上磨损过的痕迹看来，似乎又不像是做买卖的，看来这里
面一定大有文章。
LONG);
set("exits",([
"west":__DIR__"b_r04",
]));
setup();
}