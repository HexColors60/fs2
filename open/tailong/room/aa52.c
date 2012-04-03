#include <ansi.h>
inherit ROOM;

void create ()
{
  seteuid(getuid());
  set ("short", "花园");
  set ("long", @LONG
这里是天龙寺中的花园,这里不但栽满了各式各样的珍奇花草,
还种植了很多的稀有茶树,像是"霓裳羽衣、步步生莲、十八学士"
,这大概也是因为大理的茶花甲于天下,奇怪的是这里竟然种着一
点都不搭调的竹子。在旁边好像有一座高塔,过去看看吧。
LONG);

  set("search_desc/竹子",
         "你仔细的找一找，发现竹子的中间隐约有条路的痕迹，应该可以穿(pass)过去!!\n");

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"aa51",
  "northwest" : __DIR__"aa54",
  "west" : __DIR__"aa53",
]));
}
void init()
{
    add_action("do_pass","pass");
}
int do_pass(string arg)
{
    object me=this_player();

    if(!arg) return notify_fail("你想要穿过什么??\n");
    if(arg!="竹子") return notify_fail("你想要穿过什么??\n");
    message_vision(HIG"$N"HIG"用手拨开竹子，往小径走去!!\n"NOR,me);
    if(me->query("family/family_name")!="段家"){
      me->move(__DIR__"d0.c");
    }
    else{
      me->move(__DIR__"d1.c");
    }
    return 1;
}
