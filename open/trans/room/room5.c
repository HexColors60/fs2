#include <ansi.h>
inherit TRANS_ROOM;
void create()
{
    set("short","凌云村驿站");
    set("long",@LONG
这里是凌云村的驿站, 因为这里是以产稻米为主, 所以你经常可以
看到许多农夫以牛车载着一袋袋的稻米来这, 请驿站老板帮他们把稻米
运往各处.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/start/room/s4",
]));

    setup();
}
