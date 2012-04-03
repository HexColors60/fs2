#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "天魔血路");
  set ("long", @LONG
随着你一步一步踏入血魔主城...你感到一阵阵的血腥味扑鼻而来
地上各式各样不同生物的骨骸令你心生怯意...萌生退后的念头..
此通道呈直线形....似乎就要到血魔主城了。

LONG);

  set("exits", ([ /* sizeof() == 5 */
  "north" : "/open/gsword/room1/blood/room3/r3.c",
  "south" : "/open/gsword/room1/blood/room3/r1.c",

]));

  set("light_up", 1);
  set ( "no_transmit", 1 );
  setup();
}
