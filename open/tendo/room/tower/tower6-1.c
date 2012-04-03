
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "锁妖塔六楼--");
  set ("long", @LONG
你来到了是锁妖塔的倒数第三层，房内一片漆黑，伸手五指不辨，呆
立半盏，渐可分辨房内景物，你感觉这楼比刚刚素净，不过地上零零散散
的摆着七八个骷髅，和一堆堆的白骨，上面燐光闪烁，乍见之下恍如鬼火
一般，忽然你发现房间的角落有一只老妖怪站在那儿，对着你叹息。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room6-2",
  "down" : __DIR__"tower5-2",
]));
 set("objects", ([ /* sizeof() == 1 */
"/open/tendo/room/tower/npc/butcher" : 1,
]));
        set("no_transmit",1);
  setup();
}
int valid_leave(object me, string dir) {
  if(dir=="east"&&present("butcher",environment(me))) {
  return notify_fail("生死一屠吼道：想过去！先杀了我再说吧！\n");
  } 
 return 1;
}
void init()
{
        if( !previous_object()
        ||      !userp(previous_object()) )
                return;
      call_out( "fire_wound", 5,previous_object());
}

void fire_wound(object ob)
{
        if( !ob || !present(ob) ) return;
       tell_object(ob,HIR"～鬼影幢幢～你觉得胸中一阵翻滚，忽然一道血箭从你的嘴里喷了出来。\n"NOR);
       ob->add("kee",-100);
       call_out("fire_wound", 5,ob);
}


void reset()
{
        ::reset();
        delete("go_north");
}



