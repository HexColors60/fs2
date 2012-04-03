
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "锁妖塔三楼--");
  set ("long", @LONG
这里的陈设和方才的那间相似：空荡荡的，没有窗户，只有个往四楼的长梯，
以及一地的血印、破砖、和那股恼人的深蓝色，你只觉得自己不断地在喘气，仿佛
惊魂未定。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"room3",
  "west" : __DIR__"tower3-2",
]));

        set("no_transmit",1);

  setup();
}
int valid_leave(object me, string dir)
{
        if( dir=="up" )
        message("system",
 HIW"\n\t武林之中传来一道消息 : "HIY""+this_player()->name()+""HIW"勇闯"HIR"锁妖塔"HIW"第四层了 !!\n"NOR,users());
        return ::valid_leave(me, dir);
}
void init()
{
        if( !previous_object()
        ||      !userp(previous_object()) )
                return;
      call_out( "fire_wound", 3,previous_object());
}

void fire_wound(object ob)
{
        if( !ob || !present(ob) ) return;
       tell_object(ob,HIR"～鬼影幢幢～你觉得胸中一阵翻滚，忽然一道血箭从你的嘴里喷了出来。\n"NOR);
       ob->add("kee",-100);
       call_out("fire_wound", 3,ob);
}


void reset()
{
        ::reset();
        delete("go_north");
}




