#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short",HIC"刀冢"NOR);
set ("long", @LONG

经过狭小通道后，你来到一个巨大的洞穴之中，只见四周的土地上有
六座大小不一的坟墓，其中一座最大的坟墓上插者一把阴灵邪气的刀
中方的墓碑上(stone)似乎有东西, 你心情兴奋的想调查(seek)一般

                                 (金)
                                  ＊
                                               
                        (火)＊    ＊    ＊(木)
                                 (心)
                               ＊　　＊
                              (水)  (土)

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
"stone" :"莫云--葬刀于心穴！\n",
]));
  set("exits", ([ /* sizeof() == 1 */
"jump":"/open/gblade/room/mrm1/r4.c",
]));
  set("no_auc", 1);
  set("no_transmit", 1);
  setup();
}
void init()
{
add_action("do_search","seek");
add_action("do_put","push");
}
int do_search(string str)
{
  object ob,ob1;
  ob=this_player();
  if(ob->query_temp("sublade") != 9)
    return notify_fail("你丝毫寻找不出任何异状!!!\n");
if( str != "心" )
    return notify_fail("你完全寻找不出任何异状!!!\n");
message_vision("经过$N细心的调查之后，$N发现每个坟墓的墓碑都有圆的凹洞。\n",ob);
message_vision("似乎能用石头推进去一般(push)！\n",ob);
  ob->set_temp("can_put",1);
  return 1;
}

int do_put(string str)
{
mapping stones = ([
"gold-stone in 木" : 1,
"wood-stone in 土" : 2,
"earth-stone in 水" :3,
"water-stone in 火" :4,
"fire-stone in 金" : 5,
"heart-stone in 心" :6,
]);
object ob=this_player();
string name,str1,str2;
object superblade;
if(ob->query("evil-mblade")==1)
return notify_fail("你解完妖刀谜了！！\n");
if(ob->query_temp("can_put") != 1)
return notify_fail("你要放什么东西呀!!!\n");
if( !str || sscanf(str, "%s in %s", str1, name) != 2 )
{
message_vision("请 push xxx in xxx\n",ob);
}
else if(stones[str]) {
message_vision(HIW"你把石头推入坟墓，顿时坟墓嘎嘎作响！\n"NOR,ob);
if(stones[str]==1) ob->set_temp("su1",1);
if(stones[str]==2) ob->set_temp("su2",1);
if(stones[str]==3) ob->set_temp("su3",1);
if(stones[str]==4) ob->set_temp("su4",1);
if(stones[str]==5) ob->set_temp("su5",1);
if(stones[str]==6) ob->set_temp("su6",1);
} else {
message_vision(HIR"你推错石头，顿时被坟墓中的阴灵嗜去魂魄！\n"NOR,ob);
ob->unconcious();
}
if(ob->query_temp("su1")==1&&ob->query_temp("su2")==1&&ob->query_temp("su3")==1
&&ob->query_temp("su4")==1&&ob->query_temp("su5")==1&&ob->query_temp("su6")==1)
{
log_file("mblade/GET_MBLADE",sprintf("%s(%s) 解到 妖刀村雨 on %s\n"
,ob->query("name"),ob->query("id"),ctime(time()) ));
message_vision(HIW"顿时中间的坟墓～～～嘎嘎作响。\n"NOR,ob);
message_vision(HIY"顿时中间那把刀便滑落于你手上。\n"NOR,ob);
superblade=new("/data/autoload/blademan/evil-mblade1.c");
superblade->move(ob);
ob->set("evil-mblade",1);
}
return 1;
}

