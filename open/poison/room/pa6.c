// Room: /u/r/ranko/room/pa1.c
inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG
这是一条弯弯曲曲的小路，路上石子不少，踩在脚底怪不舒服
的，不时还得注意地上以免被拌倒了，两旁杂草丛生，似乎欠缺人
来打理。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"v3.c",
]));
  set("outdoors", "/open/poison");

  setup();
}
