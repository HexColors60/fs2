inherit ROOM;

void create ()
{
  set ("short", "玄机房");
  set ("long", @LONG
这里就是传说中的六脉剑圣---段誉及其妻王语嫣所居住的地方,玄机房了
,里面的摆设十分的豪华别致,有如皇宫一般,但是你找来找去,却都找不到段誉
的身影,看来段誉不在这里。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"aa22",
]));

  setup();
  replace_program(ROOM);
}
