// Room: /open/capital/room/r20.c

inherit ROOM;

void create()
{
	set("short","日落广场");
	set("long",@LONG
一个中型的广场。往南去是一条很宽的车马大道，往北去是条一般
大小的胡同。广场上有尊前朝忠臣的雕像，雕像四周围绕着小贩，这儿
俗称西市。虽然比不上东市，但相去不远，而且这儿最有名的是算命摊
子，一排全部都是，有摸骨的有测字的，千奇百怪，至于可信度就见人
见智了。

LONG);

  set("outdoors", "/open/capital" );

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r21",
  "north" : __DIR__"r19",
]) );

  set("gopath", "north" );

  setup();
}
