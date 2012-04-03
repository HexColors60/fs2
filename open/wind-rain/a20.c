// by roger
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short",HIM"掩光天"NOR);
set ("long", @LONG
忽入此室，光线仿佛都被吞噬了一般，清凉如夜，亦是不见五指， 
但觉阵阵异香扑鼻而来，抚人心神，这里便是金风细雨楼一楼楼主
的三大守护天将之一所踞卫的掩光天，若要见到楼主，就必需先将
他打倒。
LONG);



  set("exits", ([
            "north"  : __DIR__"a2",
            "south"  : __DIR__"a9",
            "enter"  : __DIR__"a18",
                ]));

  set("objects", ([ 
  __DIR__"npc/shon-to" : 1,
                  ]));
       

        setup();
}

int valid_leave(object me, string dir)

{
        if(dir=="enter" && present("shon-to",environment(me)))
  {

message_vision(HIY"项拓说: 对不起, 楼主正在休息. \n"NOR,me);

return 0;
}
return 1;
}
