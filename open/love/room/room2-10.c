#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","花园");
  set ("long", @LONG
这里算是绝情门的两侧的花园，你不要把心思放在赏花上，还是
先注意你自已吧，因为风火雷电四大护法常在这修练武技，最好
是不要遇上他们，否则你别想活着离开这。
LONG);
  
   set("objects", ([ /* sizeof() == 1 */
"/open/love/npc/2.c":1,
  ]));
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"room2-14",
  "east" : __DIR__"room1-2",
  "west" : __DIR__"room2-9",
  "south" : __DIR__"room2-6",
  ]));
  set("light_up", 1);

  setup();
}

