// Room: /open/death/blackshop
inherit ROOM;

void create ()
{
  set ("short", "鬼店");
  set ("long", @LONG
这是一间什么都没有的房间。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : "/open/death/nroad",
]));

  set("light_up", 1 );
  set("no_magic", 1 );
  set("no_fight", 1 );

  setup();
}
