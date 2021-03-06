inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "环山小径");
  set ("long", @LONG
一条环着长白山的小径，往山顶的路途还遥远，两旁的草木愈来
愈少，青绿的颜色也慢慢转变枯黄，愈往上走，空气中所蕴含的气息
愈来愈冷，而大地中似乎又隐隐透着几许的雾气。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/bembem.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"mon13",
  "southdown" : __DIR__"mon11",
]));

  setup();
}
