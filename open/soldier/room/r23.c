
#include </open/open.h>
inherit ROOM;
void create()
{
  set ("short", "闲居");
  set ("long","
    听说这里就是这组织头头的住处了，不过怎么没看到
呢??在这里丝毫感觉不到人和气息，相当闲淡的样子，在
右边有个书桌(table),上面堆满了一些唐诗，在书桌旁有
一个柜子(cabinet),在地上好像还有移动过的痕迹。。。

 ");
   set("exits", ([
   "west"   : __DIR__"r24.c",
  ]));
  set("light_up", 1);
  set("item_desc", ([ /* sizeof() == 2 */
  "table" : "这桌子好像是用上等木头雕刻出来的。\n",
  "cabinet" : "这桌子好像被动过你可以深入调查(search)看看。\n",
]));
  set("search_desc", ([ /* sizeof() == 3 */
  "table" : "在你努力不懈的情况下,你发现在桌底下有一圆盘(disc)....。\n",
  "cabinet" : "在你仔细调查后，你并没发现任何线索。\n",
  "disc" : "你发现这个圆盘可以转动(turn) :D\n",
]));

  setup();
}

void init()
{
       add_action("do_turn","turn");
}
int do_turn(string str)
{
  object me;

  me=this_player();
  if( str != "disc" )
    return notify_fail("你在转啥??，不要乱转好不好？\n");
  tell_room(this_object(),"$n用力的把圆盘往逆向转了过去。。。\n",me);
  message_vision("突然桌子跟你一起回转，$n瞬间被甩进去一个房间了!!\n",me,me);
  me->move(__DIR__"r33.c");
  return 1;
}

