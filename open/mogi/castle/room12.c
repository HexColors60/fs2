// room7.c by konn
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","古堡内部");
        set ("long","只见四周充满了浓浓的绿色妖气，令你有点喘不过气来。茫茫中只见
黄色妖怪的身影若隐若现,仿佛随时会跳出来吃人似的。你的手心不
禁以冒出了冷汗...。

");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "west"  : __DIR__"room13",
            "east"  : __DIR__"room1",
            
      ]));

        set("objects",([ /* sizeof() == 1 */
   __DIR__"npc/mob2" : 5,
      ]));

        setup();
}
