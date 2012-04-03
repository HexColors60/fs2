// Room: /open/gsword/room/gsword5-23.c
inherit ROOM;

void create ()
{
  set ("short", "帐房");
  set ("long", @LONG
这里是仙剑派的帐房，仙剑派上上下下将近千余人众，每日的开销皆是一
笔巨大金额，好在仙剑派向来行侠仗义，名间声望极高，往往有许多富翁
巨贾捐钱赞助，是以仙剑派不但无金钱问题，反而常救济穷寒人家。左首
有个柜台上面放了个白玉算盘，右边是个柜子，里面摆满了帐簿。这里充
现在是由仙剑七侠中的梅影女侠掌管。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : "/open/gsword/room/g2-15.c",
]));

  set("light_up", 1);

  set("objects", ([ /* sizeof() == 1 */
  "/daemon/class/swordsman/mayying" :1,
  "/open/gsword/npc/langirl" :1,
]));

  setup();
}
