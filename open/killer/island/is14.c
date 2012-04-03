// Room: /u/u/unfinished/room/is14.c
inherit ROOM;

void create ()
{
  set ("short", "树林尽头");
  set ("long", @LONG
一路北行, 终于穿过阴暗的树林. 来到此地, 你赫然在你的东边看到一艘搁
浅的船只, 此船不大, 观其损毁的程度, 似乎已经搁浅在这里很久了. 此地北边
与西边是海, 看来应该是小岛的西北角.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"is10",
  "east" : __DIR__"is15.c",
]));
  set("outdoors", "/u/u");

 setup();
  replace_program(ROOM);
}
