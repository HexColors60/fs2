// Room: /open/dancer/room/rooms1.c :cgy

inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
夜梦小筑的走廊，向北连接到夜梦殿堂，两旁的墙上雕塑着
许多舞者翩翩起舞的优美姿态，让你不禁驻足观赏，心中不由暗
赞雕塑者的神奇技巧，令人叹为观止。向南可到练舞场。


LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/dancer/room/start.c",
  "south" : "/open/dancer/room/rooms2.c",
]));

  set("light_up", 1);

  setup();
}
