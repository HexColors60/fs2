//__DIR__"uhen/10.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","副门主房");
        set("long",@LONG

	本为玉衡门副门主的办公房. 不过后来副门主将之改建成弟子的休息室
        让工作辛苦的门下弟子可以暂时到这间房里来休息一下. 由此可见副门
        主对部下的关心. 进来就看到二个弟子坐在椅子上泡茶聊天. □
LONG);

        set("exits", ([ /* sizeof() == 2 */
        "south":__DIR__"11",		//副门主室
	"southeast":__DIR__"9",		
 
        ]) );
        set("light_up", 1);
        set("objects",([ /* sizeof() == 2 */
   "/open/prayer/npc/trainee2" : 1,		//弟子
   "open/prayer/npc/trainee3" : 1,		//弟子
   		
]));
     
  setup();
}
