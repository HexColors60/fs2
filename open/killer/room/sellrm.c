#include <ansi.h>
#include <room.h>
inherit ROOM;
                
void create ()
{
  set ("short", "杀手贩卖部");
  set ("long", @LONG
这是杀手们接受特训后的买东西的好地方。里面应有尽有。  
如果只是想吃饱的话，可以到杀手餐厅处吃，会比较便宜哦。。。
如果想补充长期作战所需的粮草与装备，倒是不错的选择。

LONG);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r19.c",
   ]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/killer/npc/sellman.c" : 1,]));
  setup();
}