// Room: /u/l/lotus/girl/guest.c

#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "香楼大厅");
  set ("long", @LONG
张灯结彩, 一片喜气洋洋, 桌上盛放着的牡丹, 使大厅更添妩媚
色彩. 香楼来往的客人还真不少, 有一掷千金的富商巨贾, 也有风流
倜傥的才子, 墙上挂着的画, 便是出自性情才子之手.

姑娘们正笑盈盈地迎接客人.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : CENTER_ROOM"guest3.c",
  "west" : CENTER_ROOM"guest2.c",
  "east" : CENTER_ROOM"tree.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  CENTER_NPC"powyi.c" : 1,
]));
  set("light_up", 1);
  set("file_name", CENTER_ROOM"guest.c");

  setup();
}
