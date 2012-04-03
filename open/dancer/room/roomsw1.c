// Room: /open/dancer/room/roomsw1.c :cgy

inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
夜梦小筑的走廊，东边是练舞场，南北两旁的墙上雕塑
着许多美丽的雕像，令你不禁驻足观赏，向西可到梦月阁想
要生上的必需品的话就到那吧....


LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : "/open/dancer/room/rooms3.c",
  "west" : "/open/dancer/room/roomsw2.c",
]));

  set("light_up", 1);

  setup();
}
