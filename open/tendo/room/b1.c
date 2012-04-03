#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
set("short","昆仑仙境");
set("long", @LONG
这里是传说中的昆仑仙境，只见四周云烟袅袅，桃枝红花，其景
有如人间仙境一般，抬头仰望天际日月同升，群星争艳，隐约还可听
到几声高昂惊人的啼叫声，前方有条通道，应该是通往灵池的。

LONG);

        set("light", 1);
        set("light_up", 1);
        set("no_fanset", 1);
        set("no_chome", 1);
        set("exits", ([ /* sizeof() == 2 */
        "north" : "/open/tendo/room/b2",
        "back" : "/open/tendo/room/start",
        ]));

        set("objects",([
        "/daemon/class/taoist/necromancy/npc/hawk1" : 1,
        ]));
        setup();

}
