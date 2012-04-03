// Room: /u/d/devils/school2.c

#include <room.h>
#include <ansi.h>




inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
你走进正晴武馆的练武场,进门处两排长凳，分坐八名劲装结束的汉子
，个个腰板笔挺显出一股英悍之气，令你心中不自觉得恐慌了起来...
此处往东直走便是正晴武馆大厅，西边是正晴武馆大门(open door)
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "west" : (: look_door,     "west" :),
]));
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"school5",
  "north" : __DIR__"school3",
  "west" : __DIR__"school1",
  "east" : __DIR__"school7",
]));
        create_door("west", HIR"镂花红桧大门"NOR, "east", DOOR_CLOSED);

       set("outdoors", "/open/wu");
	setup();
}
