//open/prayer/room/zhenche/21.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","练武场");
        set("long",@LONG

        在练武场的西方, 有两个弟子正互相眉来眼去! 原来他们
        原本是一对夫妻, 又因为爱慕圣火的武功威名, 因此相协
        进入阵势门中习武.

LONG);

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 3 */
        "north":__DIR__"17",            //练武场
        "south":__DIR__"27",            //练武场
        "east":__DIR__"20",             //练武场
 
        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee2" : 1,              //弟子
  "/open/prayer/npc/trainee3" : 1,              //弟子
                
]));
     
  setup();
}
