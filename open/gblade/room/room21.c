// Room: /u/m/moner/tree/room19.c
inherit ROOM;
#include <ansi.h>
#include "/open/open.h"

void create ()
{
  set ("short", "囚室");
  set ("long", @LONG

这里是天邪峰囚禁犯人的牢房，儿臂粗细的铁杆内一对对阴森的眼
睛，满怖杀意的凝视着你，你每踏出一步，心里便寒寒的发毛着，牢笼内
并没有哀嚎声，反而是一片的宁静才令人越害怕。牢房内来来回回的走动
着狱卒。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room20.c",
]));
  set("light_up", 1);
set("no_transmit", 1);
  setup();
}
void init()
{
 object me = this_player();
   if(present("skykey",me))
        tell_object(me,HIW"西面的铁锁有感于你身上的钥匙而发出声响。\n"NOR);
 add_action("do_go","go");

}
int do_go(string str)
{
  object me = this_player();
  object ob = this_object();
    if(str == "west" )
         if(present("skykey",me))
            {
        tell_room(ob,"铁门感应钥匙的魔力，开起了一道门。\n");
             message_vision("$N不慌不忙地走了进去。\n",me);
             tell_room(ob,"随着钥匙离去，石门自动关上。\n");
me->move("/open/gblade/room/mrm1/r11.c");
             return 1;
            }
}
