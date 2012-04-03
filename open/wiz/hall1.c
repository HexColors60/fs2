// Room: /d/wiz/hall1.c
#include <room.h>


inherit ROOM;

void create ()
{
  set ("short", "巫师交谊厅");
  set ("long", @LONG
如果您有任何话想留给其他巫师看, 请在此地 post.  也因为这里
提供此项服务, 所以常常是巫师们聚集的地方. 当然, 巫师们每次上线
通常也都会来这儿, 如果您不常来这儿, 也许您已经漏掉不少资讯了.
    往南是程式写作房, 那边您可以发问或查询跟程式写作有关的种种
疑难杂症, 往东则是跟玩家有关的房间, 要是您常常写程式或开发某一
地区, 请您务必常常过去赏光, 也许那边会有问题等您解决呢! 往西则
是一个邮局, 最近邮局已经开发出新功能, 当您有话要私下讲的时候,
利用邮局是一个不错的选择.
LONG);

  set("valid_startroom", 1);
  set("exits", ([ /* sizeof() == 6 */
  "down" : "/u/c/chan/cl_room.c",
  "up" : __DIR__"hall3",
  "south" : __DIR__"program_room",
  "west" : __DIR__"post_office",
  "east" : __DIR__"entrance.c",
  "north" : __DIR__"jobroom",
]));


  setup();
call_other("/obj/board/wizard_b","???");   
}
