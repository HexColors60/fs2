//u/r/rence/room/zhenche/27.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","练武场");
        set("long",@LONG

        在练武场的西南角, 有两个弟子正在交换练武的心得. 一
        讲到圣火武学, 彼此眼中都散发出异样眼光, 好像都忘了
        练武的辛苦. 难道圣火的上乘武功真的这么吸引人吗?

LONG);

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"21",            
        "east":__DIR__"26",     
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
        "/open/prayer/npc/trainee1" : 1,                //弟子
        "/open/prayer/npc/trainee3" : 1,                //弟子
                
]));
     
  setup();
}
