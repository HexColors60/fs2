#include </open/open.h>
inherit ROOM;

void create ()
{
  set ("short", "莫塔湖源河边");
  set ("long", @LONG
	
	在你眼前所呈现的是一条壮阔的河流，水势不急但是却丝毫无鱼？！
	但是随后，在河中有一个石头宛如飞剑一般，快速的随水而流逝！！
	原来此河暗潮汹涌，水势湍急！！一般鱼虾根本无法在其中游泳！
	在南方似乎有小路可以沿着河边行走.........

LONG);

  set("exits", ([ /* sizeof() == 3   */
     "south" : __DIR__"hr20.c",   
     "west" : __DIR__"hr18.c",   
]));

  setup();
}
