// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","中央广场");
        set("long", @LONG
这儿是天道派用来给初入门的弟子练防身武术的地方，你放眼四
望，看见了许许多多的天道弟子在练习紫龙鞭法，他们舞出的气流把
你逼得一直往后退。
LONG);
  set("outdoors",1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/tendo/npc/boy":1,
]));
set("exits", ([
        "south":__DIR__"r28",
	"north":__DIR__"r48",
	"west":__DIR__"r44",
	"east":__DIR__"r30",
]));
  setup();
}
