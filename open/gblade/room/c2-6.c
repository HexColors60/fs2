inherit ROOM;

void create ()
{
  set ("short", "地道");
  set ("long", @LONG

地道到了这里渐渐的开始往下倾斜，你极力往前望去--黑压压的一片，什
么也看不见，四周一片死寂，耳朵也因此发出嗡嗡的声响，仿佛有无数的
蜜蜂在你耳边飞舞，你下意识的挥舞双手。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"c2-5.c",
  "east" : __DIR__"c2-7.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gblade/npc/mob5.c" : 1,
]));

  setup();
}
int valid_leave(object me,string dir)
{
	if(dir=="east"&&present("big rat",environment(me)))
	if(me->query("pass_gblade")<5)
	return notify_fail("你陷入巨鼠所挖的地洞动弹不得 !\n");
	return ::valid_leave(me,dir);
}
