#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",HIW"走道"NOR);
set("long",@LONG
一堆已经腐化的尸体气味夹杂着食物的腐败臭味直冲你鼻口，令你不由得喉咙
一阵酸涩，你掩住鼻子望了下四周，看来食物都早已经腐烂消失了，所剩的都只有
尸骨与一些烹饪器材，也许这里曾经是一些厨师大显身手的地方。
LONG);
set("exits",([
"east":__DIR__"b_r06",
]));
setup();
}