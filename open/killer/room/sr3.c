inherit ROOM;

void create ()
{
set("short","杀手宿舍");
  set ("long", @LONG
这里是极为平凡的地方，一眼望去，似乎没有一点像睡觉的地方。
这是属于杀手的特殊设计，为了怕睡觉时被暗杀，所以你一般是看不到睡觉的人。
必定随时都有人在守卫着，所以你想趁机杀了熟睡中的人是不可能的。

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
"east" : __DIR__"sr2.c",
"south" : __DIR__"sr0.c",
]));
  setup();
}