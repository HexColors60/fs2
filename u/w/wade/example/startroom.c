#include <room.h>

#define TEST "START ROOM for test"

inherit ROOM;

void create ()
{
  seteuid(getuid());
  set ("short", TEST);
  set ("long", @LONG

		你想由范例学 LPC(MudOS)?
		以后多来这儿看看啰！


LONG);

  set("exits", ([ /* sizeof() == 3 */
  "dlong"	: __DIR__"dlong",
  "tel"		: __DIR__"tel",
  "stack"	: __DIR__"stack",
]));

  setup();
}
