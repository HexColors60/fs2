#include <room.h>

inherit ROOM;

void create()
{
           set("short","紫霞组组长办公室");
         set("long",@LONG
	
	紫霞组是负责守护通吃小筑的安全，但是因为工会老大并不喜欢人家保护，
	所以与红叶组与银狼组一样，只能守护在工会老大的附近。
	因为寻常人根本进不了天灵老人的身边，所以由紫霞组最强的组长杨小七镇守。
	相传杨小七是杨小邪的知心好友，两人的友情并非寻常人可以得知。
 
LONG);
        set("exits", ([
	"south":__DIR__"hru1.c",
        ]) );
        set("objects",([
          "/open/killer/npc/hu_fa4.c":1
	,]));
        setup();
}
