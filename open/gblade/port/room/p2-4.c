// Room: /open/gblade/port/room/p2-4.c
inherit ROOM;

void create()
{
	set("short","宠物店");
  set ("long", @LONG
这里是全国唯一的一家宠物店 , 买卖各式各样动物 , 你可
以买去作伴 , 也可以买去好好训练 , 与你共闯江湖 , 现在这
里还在缺货中 , 相信很快就会有货源运到啦 !


LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"p2-3",
]));
  setup();
}
