// by roger
inherit ROOM;
#include <ansi.h>
#include "wind-rain.h"
void create () {
set ("short","芙蓉湖旁");
set ("long","这里是芙蓉湖畔，道路一边临湖，一边是整排的雕楼画栋。湖上金风
细细，烟雨迷迷。远方有山，为天泉山；山上有塔，为玉峰塔。山旁有一
楼，为金风细雨楼。"HIY"‘风雨楼中吹玉笛，江城五月落梅花’"NOR"，金风细雨楼
是京师第一大势力，统辖江湖黑白两道中没有宗派或组织的势力。权势醉
人，斗争从来不曾停过，风雨愁人，风雨楼的风雨也不曾歇过。 
");


  set("exits", ([
            "east"  : "/open/capital/room/r25",
            "west"  : __DIR__"room2",
                ]));

       

        setup();
}
