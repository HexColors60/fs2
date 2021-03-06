// Room: /open/ping/room/pingking
inherit ROOM;
#include <room.h>
#include <ansi.h>

void create ()
{
  set ("short", "段王府门口");
  set ("long", @LONG
这里便是段王府, 段王府是整个平南城的中心, 在数百年前, 这儿
方圆数百里的地方是一个小国, 整个小国便是由段家的人所统治着, 如
今这里以归顺朝廷统治, 而原本的段家因归顺的缘故, 也受封为平南王
只是这儿的人还是习惯称呼其为段王府。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/duan-guard.c" : 2,
]));
  set("outdoors", "/open/ping");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road7",
  "enter" : __DIR__"np1.c",
]));

  setup();
}

void init ()
{
  object me=this_player ();
  if (me->query_temp("six_sp_quest") == 4)
      {
       message_vision("\n你刚出大门, 突被一阵疾风撞倒, 只见一名僧侣急忙扶起你, 连声道歉.\n",me);
       message_vision(HIY"特上级武僧说道:对不起, 没撞伤你吧, 小僧有‘急事’告知你师父, 才如此匆忙. \n"NOR, me);
       message_vision("说完, 便向府中奔去, 你满怀好奇, 急忙也跟了进去. \n\n",me);
       me->set_temp("six_sp_quest",5);
      }
}
