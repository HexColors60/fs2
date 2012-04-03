// Room: /d/oldpine/epath2.c

inherit ROOM;

void create ()
{
  set ("short", "仙剑派前山");
  set ("long", @LONG
    前进到此,只见巨石耸立,水声淙淙,阵阵水气袭来,带给你满面清凉,
道路在此转向北方,你直觉你已经到仙剑派外围.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road1.c",
  "east" : __DIR__"mroom6.c",
]));

  set("outdoors", "/open/gsword/room");

  setup();
}
