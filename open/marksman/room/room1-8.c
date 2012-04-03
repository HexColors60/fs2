inherit ROOM;
#include <ansi.h>
#include <marksman.h>
void create ()
{
  set ("short", GRN"长沙道"NOR);
  set ("long", @LONG
轻风轻轻的往我的脸颊吹过，白蓝蓝的天空似乎多了一飞兽在空
飞舞着。从长沙道上可以清楚的听见鸟儿的歌声，在空中自由的飘扬
着。
LONG);

  set("exits", ([ /* sizeof() == 2 */
"south" : __DIR__"room1-3",
"north" : __DIR__"room1-9",
]));
set("outdoors","/open/marksman");

  setup();
}
