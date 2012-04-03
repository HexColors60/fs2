#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short", "锁妖塔入口");
  set ("long", @LONG
    这儿是传说中的「锁妖塔”，你仰头算了算，塔高正好八层，塔身漆着像血渍
般的暗红色，给人一种不寒而栗的感觉。  塔内杂草没胫，虫鸣如泣，偶而还夹杂
着一两声夜枭悲鸣之声，和分不清是神嚎? 还是鬼哭的声音? 塔上鬼影幢幢，忽隐
忽现，显得格外神秘，阴森，而恐怖 !!
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"road3",
  "enter" : __DIR__"tower1-1",
]));
  set("outdoors",1);
  setup();
}
int valid_leave(object me, string dir)
{
        if( dir=="enter" )
        message("system",
 HIW"\n\t武林之中传来一道消息 : "HIY""+this_player()->name()+""HIW"勇闯"HIR"锁妖塔"HIW"第一层了 !!\n"NOR,users());
        return ::valid_leave(me, dir);
}



