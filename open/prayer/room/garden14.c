//open/prayer/room/garden14.c
#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","花园");
        set("long",@LONG

	    这个花园颇大，往东往西往南都是浓浓的
	雾气，整座花园弥漫着一种说不出的诡异气氛
	，时有听到野兽咆哮的声音，时而闻到浓厚的
	血腥味道令你不寒而颤。

LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 3 */
        "north":"/open/prayer/room/garden18",		//花园
        "south":"/open/prayer/room/garden10",			// "
        "west":"/open/prayer/room/garden15",			// "
        ]) );
   setup();
}
