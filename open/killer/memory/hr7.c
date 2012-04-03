#include </open/open.h>
#include "ansi.h"
inherit ROOM;

void create ()
{
  set ("short", "通吃小筑");
  set ("long", @LONG

   这是由天才机关手诸冈渡与天灵老人，两人合力完成的迷阵屋
   放眼望去每个房间长的都一样，让你难以分辨，到底要如何去行走
   如果想出去，赶快打BACK退出去吧........................
   在一旁有竖立了一个标示牌(sign)
   

LONG);
  set("exits", ([ /* sizeof() == 3   */
     "north" : __DIR__"hr9.c",
     "back" : __DIR__"hr5.c",   
]));
  set("item_desc", ([ /* sizeof() == 2 */
        "sign":"想加入杀手工会的话，或是资深杀手想见工会老大，请打 meet black\n",
]));
 set("objects",([
  "/open/killer/npc/spy4.c":2,]));
  setup();
}

void init()
{
	add_action("do_meet","meet");
//	add_action("do_look","look");
}

int do_look(string str)
{
  object me;

   if(str )
    return notify_fail("你想看什么？？看看有没有人救你吗？？用哭的比较快啦！！\n");
//::look();
}

int do_meet(string str)
{
  object me=this_player();

   if( str != "black" )
    return notify_fail("你想去会见谁呀？？\n");

if(me->query("class") != "killer")
{
	 if(me->query("class"))
		return notify_fail("你以为你是谁呀，也想要去见他？自己找路吧！！\n");
	//表示不是杀手且为平民，想要加入杀手者
	if (me->query("quest/rain") != 1)
	message_vision(HIG"突然由一旁出现一位紫霞组的高手！！！\n"NOR,me);
	message_vision(HIG"一阵灰暗后，你居然来到了工会老大面前........！\n"NOR,me);
	me->move(__DIR__"hru2.c");
	return 1;

}
	//表示是杀手，想要去见工会老大者，但没有解过魔气杀之谜者
  if (me->query("quest/rain") != 1)
	return notify_fail("孩子，你的能力不足，也想要去见他？必须要自己找路哦！！\n");
	//有解过魔气杀的杀手
  message_vision(HIG"突然由一旁出现一位紫霞组的高手！！！\n"NOR,me);
  message_vision(HIG"一阵灰暗后，你居然来到了工会老大面前........！\n"NOR,me);
  me->move(__DIR__"hru1.c");
  return 1;
}
