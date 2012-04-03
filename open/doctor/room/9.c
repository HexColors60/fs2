#include <room.h>
inherit ROOM;
void create()
{
        set("short", "客房");
        set("long", @LONG

    一间宽敞舒适的客房，一张圆桌上正摆着刚沏好的茶，煦和的阳
光从窗口照到地板上，多么幽雅的环境，的确是一间适合招待远客下
蹋，看桌上的茶正热着，不知道此地来了哪位贵宾？

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"6",            
        "east":__DIR__"8",          
        ]) );
        set("light_up", 1);
        set("objects", ([ /* sizeof() == 1 */
        "/open/doctor/npc/chan" : 1,
]));

   setup();
}


