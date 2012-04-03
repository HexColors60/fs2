// Room: /open/capital/room/r60.c

#include </open/open.h>
inherit ROOM;

void create ()
{
  set ("short", "竞技场前广场");
  set ("long", @LONG
北方是城内著名的竞技场，由于王朝人人崇武，因而干通天趁机在
此开设竞技场供各方好手切磋武艺，一年一度的武状元选拔也是在此举
行的。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"fight",   
  "west" : __DIR__"r59",
  "east" : __DIR__"r62",
]));
  set("outdoors", "/open/capital");
set("objects",([
	CAPITAL_NPC"g1"	: 1,
	CAPITAL_NPC"g0"	: 1,
]));

  setup();
}
