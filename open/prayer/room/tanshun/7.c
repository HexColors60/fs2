//u/r/rence/room/tanshun/7.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","议事厅");
        set("long",@LONG

        在议事厅的东南角, 有一个总教头正在报告门中弟子□武
        的情形. 说到得意处, 不禁露出得意的笑容! 似乎对这次
        三年一度的比武大会抱着极大的信心!

LONG);
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"4",             //议事厅
        "west":__DIR__"8",              //议事厅
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
        "/open/prayer/npc/general-officer" : 1,         
]));

   setup();
}
