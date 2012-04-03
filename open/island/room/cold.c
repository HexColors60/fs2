#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", HIB+"寒冰洞"+NOR);
  set ("long", @LONG
这里是寒冰洞的最里层 ,森森的寒气仿佛要刺进骨头里去
似的 ,你的气力正一点一滴的流失 ,眼前有个像巨大石块般的
东西 ,原来是巨大无比的乌龟....


LONG);
 set("exits", ([ /* sizeof() == 4 */
  "southwest" : "/open/island/room/c1",
    "southeast" : "/open/island/room/c3",
  "east" : "/open/island/room/c2",
]));
set("objects", ([ /* sizeof() == 1 */
  "/open/island/npc/turtle" : 1,
]));


 
 set("light_up", 1);
 
 setup();
}
void init()
{
  object ob;
  if( interactive( ob= this_player()))
   {
        // 5秒后呼叫
        call_out("greeting", 2, ob);
   }
  add_action("do_team","team");

}

int greeting (object who)
{
  object room=environment(who);
//  判断player是否在这个房间
  if(this_object() == room )
 who->add("kee",-70);
return 1;
}

int do_team(){
   object me=this_player();
   tell_object(me, "你手脚冰冷的不听使唤!!\n");
   return 1;
}

