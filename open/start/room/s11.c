// Room: /open/start/room/s11.c

inherit ROOM;

void create ()
{
  set ("short", "凌云村");
  set ("long", @LONG
平静安详的村庄，两旁见到的都是平凡的民舍，
没有什么特殊的建筑，远向南方望去是一片绿油油的
稻田，有几个农夫正在辛勤的耕作。
    北面是村长的房舍。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : "/open/start/room/s10",
  "north" : "/open/start/room/s12",
  "east" : "/open/start/room/s14",
]));

  set("outdoors", "/open/start");

  setup();
}
