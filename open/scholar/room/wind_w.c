inherit ROOM;

void create ()
{
  set ("short", "西堂风");
  set ("long", @LONG
不知道是不是迷信的关系，总觉得站不太稳似的，摇摇欲坠的感
觉，是地板在摇晃吗？还是自己头昏？这里空气让人想吐，是书放太
久的原因吧。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wind",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/scholar_wind.c" : 1,
]));

  setup();
}
