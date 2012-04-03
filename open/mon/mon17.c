inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "碎石坡");
        set ("long", @LONG
愈往前走，地面仍旧满怖了碎石，景色依旧，在两旁草木更显枯
黄稀少，空气中的水气也愈来愈浓，冷冷的风疾疾的吹，寒冷的气息
也一点一滴的钻进你的体内，让你摸不清前方的路还有多远。
LONG);
        set("outdoors", "");
        set("exits", ([ /* sizeof() == 4 */
        "northup"    : __DIR__"mon18",
        "eastdown"   : __DIR__"mon16",
]));
        setup();
}

