// Room: /open/poison/room/v10.c
inherit ROOM;

void create ()
{
  set ("short", "小木屋内");
  set ("long", @LONG
这是一间以木头盖的简陋的木屋，是村长号召村里的状丁合力
替将军盖的，而将军为了感谢村人的帮忙，亦留在此地协助维护村
里的安宁，免受外来的侵害。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"pa4.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/general.c" : 1,
]));
  set("light_up", 1);

  setup();
}
