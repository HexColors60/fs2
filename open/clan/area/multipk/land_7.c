// land_7.c by ACKY

inherit ROOM;
#include <ansi.h>
#include <land.msg>

void create()
{
	set( "short", HIG"������ԭ��"NOR );
	set( "long", (: print_msg :) );
	set( "no_transmit", 1 );
	set( "light_up", 1 );    
        set( "exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"land_4",
		"east"  : __DIR__"land_8",
	]));
        setup();
}

