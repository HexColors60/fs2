#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", HIB+"寒冰洞"+NOR);
  set ("long", @LONG
你跌入了一个阴寒的洞中 ,四周的寒气冻得人手脚皆不灵
光 ,你正走在一块巨大的冰棚上 ,幽蓝的光芒自遥远的冰下透
上来 ,透着诡异而迷离的气氛...


LONG);
 set("exits", ([ /* sizeof() == 4 */
  "west" : "/open/island/room/c22",
    "east" : "/open/island/room/c20",
  "north" : "/open/island/room/c17",
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




