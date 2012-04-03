
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "锁妖塔六楼--");
  set ("long", @LONG
你来到了是锁妖塔的倒数第三层，房内一片漆黑，伸手五指不辨，呆
立半盏，渐可分辨房内景物，你感觉这楼比刚刚素净，不过地上零零散散
的摆着七八个骷髅，和一堆堆的白骨，上面燐光闪烁，乍见之下恍如鬼火
一般。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"room6",
  "west" : __DIR__"tower6-1",
]));
        set("no_transmit",1);
  setup();
}
int valid_leave(object me, string dir)
{
        if( dir=="up" )
        message("system",
 HIW"\n\t武林之中传来一道消息 : "HIY""+this_player()->name()+""HIW"勇闯"HIR"锁妖塔"HIW"第七层了 !!\n"NOR,users());
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




