//open/prayer/zhenche/22.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","总管的书房");
        set("long",@LONG

        在总管的书房两旁, 站着几位保镳. 他们都是由总管亲自
        在门内弟子中精心挑选出来的, 负责保护总管的安全, 以
        及看管总管书房内的重要物品.

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "southwest":__DIR__"28",                //总管房
        "west":__DIR__"23",             //总管房
       
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/paltoon1" : 1,              //保镳
                
]));
     
  setup();
}
