#include <room.h>

 inherit ROOM;

void create ()
{
  set ("short", "八卦亭");
  set ("long", @LONG
这个八卦亭算来已有一百多年的历史了，虽然老旧，但却不失其状阔的气度。
八根石柱上分别雕刻着‘天’，‘泽’，‘雷’，‘水’，‘地’，‘山’，
‘风’，‘火’隐隐中似乎含意甚高。中间的一张石桌以纯白奇岩所造，更显
八卦亭的不平凡。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lroad2",
]));
  set("outdoors", "/open/gsword/room");

  setup();
}
