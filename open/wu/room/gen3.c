inherit ROOM;
#include <ansi.h>
void create ()
{
  seteuid(getuid());    // 不是说要加这一行吗?
        set("short",HIC"-四象迷宫-"NOR);
        set("long", @LONG
虚幻漂渺你不知身在何方，眼前竟是各种古代神兽，有青龙、朱崔、神龟
、白虎。且不时发出阵阵的吼声、使你不知如何是好。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "青龙" : "/open/wu/room/gen3",
  "白虎" : "/open/wu/room/gen2",
  "朱雀" : "/open/wu/room/gen4",
  "玄武" : "/open/wu/room/gen4",
]));
  set("no_transmit",1);
  set("no_auc",1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/wu/npc/corpse" : 4,
]));
  setup();
}
