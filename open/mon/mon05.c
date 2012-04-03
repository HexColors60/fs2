inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "河岸边");
        set ("long", @LONG
一条小河出现在你的眼前，河水清彻的可以见底，河中小鱼悠然
的游来游去，诉说着与世无争的模样，让你不忍心去伤害他们。河岸
旁还有座小桥，是通往长白山上唯一的一座桥。
LONG);
        set("outdoors", "");
        set("exits", ([ /* sizeof() == 4 */
        "south" : __DIR__"mon04",
        "north" : __DIR__"mon06",
]));
        setup();
}

