#include <room.h>
inherit ROOM;
void create ()
{
   set ("short","蓝凤组组长房间");
   set ("long", @LONG
	利用五鬼搬运大法，你终于来到蓝凤组的组长所在地，
	四周被一种阵式所包围，你并没有看到任何通道。
        在你眼前的想必是蓝凤组的组长---乔小雨。

LONG);
  set("no_fight",1);
  set("no_magic", 1);
  set("no_transmit",1);
  set("objects",([
	"/open/killer/headkill/npc/hu_fa5.c":1,
        "/open/main/obj/torch" : 1,
        ]));
  setup();
}