#include <room.h>
inherit ROOM;
void create()
{
        set("short","玄关");
        set("long",@LONG
这里是银针门的玄关，往里面 (open door)走，则是银针门的诊疗
室，外面则是银针门的木人或铜人场，木人场里到处都是习武强身或辨
识穴道的弟子。

LONG);
        set("item_desc", ([ /* sizeof() == 1 */
      "north" : (: look_door,     "north" :),
]));

        set("outdoors", "/open/prayer/room");
        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"8",           
        "south":__DIR__"16",        

        ]) );

        set("objects",([ /* sizeof() == 1 */
  "/open/doctor/npc/duty" : 2,       

]));
        
        set("light_up", 1);
        create_door("north","红木刻纹大门", "south",DOOR_CLOSED);
  setup();
}


