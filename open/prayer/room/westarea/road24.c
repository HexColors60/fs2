//open/prayer/room/westarea/road24.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","街道");
        set("long",@LONG
	西武林自成一格的街道, 四通八达, 处处繁华. 东边是进入圣
	火教分部之一的"开阳门", 门主是中原隐归的一位师太, 身怀
	其本家绝学, 贵为掌门人, 可是却跑到西域来当一个门的门主
	, 难道这其中......
LONG);

        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
       	"north":__DIR__"road19",		//街道
	"south":__DIR__"road27",		//街道
	"east":"/open/prayer/room/kiyan/2-door", //街道
	
        ]) );
        
        set("no_fight", 0);
        
  setup();
}
