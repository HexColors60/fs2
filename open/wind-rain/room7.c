// by roger
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short","芙蓉湖畔");
set ("long", @LONG
    市肆依然热闹，卖针线的小开跟一个打扮得花枝招展的小丫鬟正在
打情骂俏，一名家丁正在替公子哥儿的主人卸下马鞍，另一名正在清洗
下马石。买鸡的正在和卖鸡的讲价钱，大概忘了竹笼里的那些鸡不同意
所以咯咯乱叫地十分厉害。马房里的马匹，因饲料不甚满意，也长嘶起
来，交织成一片。
LONG);



  set("exits", ([
            "east"  : __DIR__"room4",
            "west"  : __DIR__"room8",
                ]));

       

        setup();
}
