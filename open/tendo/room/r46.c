// by borstquc
#include <ansi.h>
inherit ROOM;

void create()
{
  string long;

set("short","����㳡");
        set("long", @LONG
���������������������ŵĵ��������������ĵط����������
�����������������������������ϰ�����޷������������������
��Ƶ�һֱ�����ˡ�
LONG);
  set("outdoors",1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/tendo/npc/boy":1,
]));
set("exits", ([
        "south":__DIR__"r43",
	"north":__DIR__"r49",
	"east":__DIR__"r47",
	"west":__DIR__"r39",
]));
  setup();
}