#include </open/open.h>
inherit ROOM;

void create ()
{
  set ("short", "交叉路口");
  set ("long", @LONG

   你来到了一个广大的山谷之中。前方似乎有一个建筑物。
   东北方是一片山林群，树木并不是很多。
   在一旁有竖立了一个标示牌(sign)
   

LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 3   南方要接回后山的房间中*/
     "northeast" : __DIR__"hr2.c",
     "north" : __DIR__"hr5.c",
     "south" : "/open/killer/mon/room/wood14.c",   
]));
  set("item_desc", ([ /* sizeof() == 2 */
        "sign":" 杀手工会老大所在山区，\n如果不是来入籍的平民请尽速离开\n",
]));

  setup();
}
