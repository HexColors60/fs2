//open/prayer/room/youkoun/22.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","密道");
        set("long",@LONG

        原来这里是一条密道, 密道内有一股很奇怪的臭味直扑鼻
        而来, 密道内灯光昏暗异常, 实在不像是一个崇拜火焰之
        神的教派应有的情景!!密道中鬼影幢幢, 你还是不要冒着
        危险强行进入比较好!!

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"23",    
        "east":__DIR__"3",      
 
        ]) );
        set("no_fight", 0);
                
  setup();
}
