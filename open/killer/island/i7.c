inherit ROOM;

void create ()
{
  set ("short", "船舱通道");
  set ("long", @LONG
房间一, 叙述未想....
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"i6.c",
]));

  setup();
}
