// Room: /u/m/moner/open/room/r12.c 
inherit ROOM;
#include <ansi.h>
#include <room.h>
 
void create ()
{
  set ("short", "庭园");
  set ("long", @LONG

    走进园内, 愈发的感到幽静, 淡淡的草香扑面而来, 艳阳, 微风,
绿荫, 构成了一幅风景画, 十二棵大橡树排成一列, 像是欢迎你的来到
, 随着橡树大道望去, 风行山寨主建筑物就在大道尽头, 一坐喷泉正吐
出盈盈水柱,在阳光下正显得晶莹.


LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r11.c",
  "south" : __DIR__"r13.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "south" : (: look_door,     "south" :),
]));
  set("outdoors", "wind");
create_door("south",HIW"白铁滨花门"NOR,"north",DOOR_CLOSED);

  setup();
  replace_program(ROOM);
}
