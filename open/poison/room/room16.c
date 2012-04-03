// Room: /open/poison/room/room16
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "丹药房");
  set ("long", @LONG
这是一间什么都没有的房间。
LONG);

  set("light_up", 0 );
  set("no_magic", 0 );
  set("valid_startroom", 0 );
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room13",
]) );
  set("need_key/east",1);
  create_door("east","红花木门","west",DOOR_LOCKED);
  set("no_fight", 0 );
  set("no_clean_up", 1 );
  set("file_name", __DIR__"room16" );
  setup();
}
