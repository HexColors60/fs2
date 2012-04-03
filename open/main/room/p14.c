// Room: /open/main/room/p14.c

inherit ROOM;

void create ()
{
  set ("short", "沼泽");
  set ("long", @LONG
这是一片充满污泥的沼泽,几支芦苇抽枝而起,却掩盖不住
这里的泥狞与恶臭,点点浮萍漂在地面的污水上,你恨不得敢快
离开.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : "/open/main/room/p8",
  "west" : "/open/main/room/p13",
  "south" : "/open/main/room/f12",
  "east" : "/open/main/room/p15",
]));

  set("outdoors", "/open/main");

  setup();
}
