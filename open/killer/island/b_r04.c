#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",HIW"走道"NOR);
set("long",@LONG
东边有一间房间，门槛上一样写着一些字，但多了几个你看的懂得汉字，你突
然回想起掌厨的鲁仝所给的护身符，上面的字体跟你眼前所见的型态类似，难道这
艘船是东瀛人所建造的？
LONG);
set("exits",([
"north":__DIR__"b_r03",
"south":__DIR__"b_r05",
"east":__DIR__"room02",
]));
setup();
}