// Room: /open/dancer/room/dream.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", HIY"幽雅的庄院"NOR);
  set ("long", @LONG
在你的面前是一座幽雅的庄院，而四周则种满了鲜花传来阵阵花
香，看来此处就是传说中的夜梦小筑了。门口还有两位美丽的少女在
看守着。你的心情不由兴奋起来，心想快能见到月牙儿了。


LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : "/open/dancer/room/r12-2.c",
  "enter" : "/open/dancer/room/rooms5.c",

]));
   set("objects", ([ /* sizeof() == 1 */
   "/open/dancer/npc/rgirl.c" : 2,
  ]));

  set("light_up", 1);

  setup();
}
 int valid_leave(object me, string dir)
{
if( dir=="enter" )
  if( me->query("gender")!="女性")
   return notify_fail("只有女人才能进夜梦小筑喔!\n");
return ::valid_leave(me,dir);
 }
