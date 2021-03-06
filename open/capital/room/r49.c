// Room: /open/capital/room/r49.c

#include </open/capital/capital.h>
inherit ROOM;

void create()
{
	set("short","日升广场");
	set("long",@LONG
一个中型的广场。往南去是一条很宽的车马大道，往北去是条一般
大小的胡同。广场上小贩聚集，热闹非凡。这儿是京城一等一的大市集
，因为处在城东，人们习惯称做东市。全国的南北杂货都要经过这里，
再由各地的商人转手运送买卖。所以你可以看到各种景象，有胡人牵马
来卖的，满人赶着一车人蔘的，甚么都有。

LONG);


  set("outdoors", "/open/capital" );

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r50",
  "south" : __DIR__"r48",
]) );

  set("gopath", "south" );
  set("objects",([
  "/open/capital/npc/vendor":1,
  ]));

  setup();
}
