#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "洞穴");
  set ("long", @LONG
看到从第一层传到这里的光线,有点向柳暗花明又一村的感觉,经历这样长时间在伸手不见五指的环境下,现在的你只想赶快往下离开。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hole26",
]));

  setup();
}
