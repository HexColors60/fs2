#include </open/open.h>
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "寝居");
  set ("long", @LONG
这里是三师兄段远风的住处, 里头有床椅等家具, 布置的温暖舒
适墙上挂了许多精美的字画, 都是段远风的手笔, 你不禁钦佩他文武
全才。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"np14",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "south" : (: look_door,     "south" :),
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/duan3.c" : 1,
]));

  setup();
}
