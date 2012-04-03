#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"天地破魔阵"NOR);
        set("long", @LONG
浑浑噩噩之间..你来到的破魔阵的阵眼,耀眼的七彩光芒..闪烁不定.寻寻觅觅中
你发现在你正上方..七颗无比耀眼的奇异矿石.依一个你不知道图形排列..矿石外
被几个半透明的光圈包围...另你不知其作用为何。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
 "north":"/open/gsword/room2/tesinroad.c",

]));
        set("light_up",1);
        set("no_transmit", 1);
        setup();
}

void init()
{
  object ob;
  if( interactive( ob= this_player()))
   {
      remove_call_out("greeting");
        call_out("greeting", 0, ob);
   }
}
int greeting (object who)
{
  object room = this_object();
  object mob;
  int i;
  if(who->query("bellicosity") > 500+random(100)) {
    message_vision(HIR"\n$N进入天地破魔阵后..瞬间阵眼中的破魔七星发出耀眼光芒.\n",who);
    message_vision(HIR"光芒消失后，数条骇人之巨龙向$N冲来！！！\n"NOR,who);
    seteuid(getuid());
    i=random(5)+1;
    while(i--)
   {
      mob=new("/open/gsword/npc2/t_dragon");
      mob->move(room);
      mob->callset(who);
      mob->kill_ob(who);
    }
  }
  return 1;
}
int valid_leave(object me, string dir)
{
if((dir=="north" || dir=="south" || dir=="east" || dir=="west")&& present("dragon",environment(me)))
    if(!me->query_temp("allow_read",1))
   return notify_fail("你以为你能活得过去吗??"+RANK_D->query_respect(me)+"你去死吧!\n");

return ::valid_leave(me,dir);
}

