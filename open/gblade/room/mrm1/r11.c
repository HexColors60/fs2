// Room: /u/m/moner/water/mblade/r9.c
inherit ROOM;

void create ()
{
  set ("short", "牢房");
  set ("long", @LONG

这是一间黑牢，暗无天日的室内囚禁着一个人，地上满怖着水泽，
室内仅有一座石床。

LONG);

  set("exits", ([ /* sizeof() == 1 */
"east":"/open/gblade/room/room21.c",
]));
set("objects",([
"/daemon/class/blademan/npc/waman.c":1,
]));
set("no_transmit", 1);
  setup();
}
