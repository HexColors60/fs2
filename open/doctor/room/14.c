#include <room.h>
inherit ROOM;
void create()
{
        set("short", "走廊");
        set("long", @LONG

    学医本是为救人，银针门对于魔教使毒暗算他人的下流手段更是
恨之入骨，如果你是魔教弟子，最好不要久留于此。

LONG
        );

        set("exits", ([ /* sizeof() == 2 */
        "east":__DIR__"12",           
        "west":__DIR__"15",      

        ]) );

  setup();
}

int valid_leave(object me, string dir)
  {
    if(dir=="east"&&me->query("gender")=="女性")
        return notify_fail("女人是无法进入副门主的办公房的 !\n");

   return 1;
}

