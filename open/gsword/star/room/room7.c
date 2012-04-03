// Room: /u/b/blue/room/star1.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "走道");
  set ("long", @LONG
你刚刚迈入七星塔第四层, 在此处你看到了满地的血迹, 
四周只有微微光线, 朦朦胧胧, 远远的望去, 只看到一点亮光
, 令你想立刻飞奔过去, 只见一阵阵的阴风扑面而来, 此时才
发觉有许多鬼影向你这奔来．
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room8.c",
  "down" : __DIR__"star3.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/star/npc/corpse.c" : 4,
]));
  set("light_up", 1);

  setup();
}
int valid_leave(object me, string dir)
{
if( dir=="north" && present("corpse",environment(me)))
    if(!me->query_temp("allow_read",1))
   return notify_fail("你以为你能活得过去吗??"
+RANK_D->query_respect(me)+"你去死吧!\n");
return ::valid_leave(me,dir);
}
