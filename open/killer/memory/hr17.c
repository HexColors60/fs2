#include </open/open.h>
inherit ROOM;

void create ()
{
  set ("short", "断崖");
  set ("long", @LONG

	天啊！！在你眼前的一个深不见底的巨大山谷，与东方的另一山脉
	形成了一个直角的垂直山谷，远远望去可以方现东方的山谷有一条巨大的河流
	莫非那一条河流就是莫塔湖的源河？令你不禁想一探究竟........
	
LONG);

  set("exits", ([ /* sizeof() == 3   */
     "east" : __DIR__"hr18.c",   
     "south" : __DIR__"hr16.c",   
]));

  setup();
}
