// Room: /u/b/blue/room/star1.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "玉衡楼门口");
  set ("long", @LONG
你经过走道, 终于来到了这, 你已发觉到眼前有一道门 
在门的上面有一块扁额, 上面写着玉衡楼, 此时楼外有两个
守卫拦住你的去路, 令你心中忿恨不已, 想痛扁守卫一番。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room3.c",
  "enter" : __DIR__"star2.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/star/npc/swordsman.c" : 2,
]));
  set("light_up", 1);

  setup();
}
int valid_leave(object me, string dir)
{
if( dir=="enter" && present("swordsman",environment(me)))
    if(!me->query_temp("allow_read",1))
   return notify_fail("你以为你能活得过去吗??"
+RANK_D->query_respect(me)+"你去死吧!\n");
return ::valid_leave(me,dir);
}
