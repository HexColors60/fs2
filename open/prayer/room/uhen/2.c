//__DIR__"2.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","书房");
        set("long",@LONG

	书房的书柜全部都是以西洋橡木做成的，高有数丈．柜
	中四处可见古诗古词的书本，内中还参杂不少的武学图
	腾．

LONG);
        set("exits", ([ /* sizeof() == 1 */
        "west":__DIR__"3",		//右护法
 
        ]) );
        set("no_fight", 0);
        set("light_up", 1);
  setup();
}

