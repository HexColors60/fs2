// Room: /open/poison/room/road14
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "大门");
  set ("long", @LONG
这里是冥蛊魔教的大门口，大门两旁有一对栩栩如生的
石狮，两眼直视前方，一副傲视群雄的神态，门旁一棵垂柳
随风飘曳。
LONG);
  set("light_up",1);
  set("outdoors", "/open/poison");

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/poison/room/road15",
  "southdown" : "/open/poison/room/road13",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/guard" : 1,
]));
  setup();
}

int valid_leave(object me, string dir)
{
   int number;
   number  = me->query_temp("poison_nopass");
   if (dir=="north" &&
       present("guard",this_object()) &&
       me->query("family/family_name") != "冥蛊魔教" )
   {
	if (number > 1) {
          me->set_temp("poison_nopass",number+1);
          return notify_fail(HIC"冥蛊守卫喝道：有我在，休想进入。\n"NOR);
        }
        if (me->query_temp("weapon")) {
          me->set_temp("poison_nopass",number+1);
	  message_vision(HIC"冥蛊守卫怒道：不准带武器入内，$N想到此滋事呀。\n"NOR,me);
          return notify_fail(HIC"冥蛊守卫喝道：这里可能会不欢迎你。\n"NOR);
        }
   }
   return ::valid_leave(me ,dir);
}
