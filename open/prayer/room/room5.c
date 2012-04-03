// Room: /u/r/rence/room/room5.c

#include <room.h>
#include "/open/open.h"

inherit ROOM;

void create()
{
        set("short","泷山迷宫");
        set("long",@LONG
这里充满着神秘的感觉，在四周各有一扇门，不知是通往何处，
七杀塔内的密秘到底是什么呢? 这些门的背后到底通到那? 然
而在石壁上有刻着：

          
          「东西南北，阴阳无极，破乾坤”

LONG);
        set("outdoors", "/u/r/rence");
        set("exits", ([ /* sizeof() == 4 */
        "杜门":__DIR__"room1",
        "伤门":__DIR__"room2",
        "景门":__DIR__"room3",
        "开门":__DIR__"room4",

        ]) );
        set("no_fight", 0);
        set("objects",([ /* sizeof() == 3 */
  "/u/k/kael/npc/kaio-mob.c" : 1,
  "/u/k/kael/npc/kmob1.c" : 2,
  "/u/k/kael/npc/kmob2.c" : 2,
]));
  setup();
}