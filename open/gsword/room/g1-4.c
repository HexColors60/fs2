// Room: /open/gsword/room/nghouse.c
inherit ROOM;

void create ()
{
  set ("short", "大长廊");
  set ("long", @LONG
这儿的长廊跟西面的比起来显的又宽的多了，两侧的墙壁上满是当年
仙剑派的开山祖师〔逍遥子〕大战群魔的情景，看着祖师爷身形飘忽，一
只木剑在手中竟能使的如此浑圆如意，看的你心炫神怡。北边有个大广场
。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/gsword/room/g1-3.c",
  "north" : "/open/gsword/room/g2-12.c",
]));

  set("light_up", 1);

  setup();
}
