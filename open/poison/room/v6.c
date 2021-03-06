// Room: /open/poison/room/v6.c
inherit ROOM;

void create ()
{
  set ("short", "猪舍");
  set ("long", @LONG
一间以砖砌成的猪舍，地上铺上了泥浆供猪只们打滚，泥浆中
混杂了猪粪和一些不知名了秽物，臭气薰天，让人闻了恶心不已。
这里养了各式各样的猪只，黑猪、白猪、公猪、母猪、小猪，每一
只都是懒洋洋的躺在泥巴中休息，有几只猪因你的到来而抬起头来
看看，但发觉你手中没有食物便又低下头睡觉去了。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"v2-8.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 3 */
   "/open/poison/npc/pig3.c" : 2,
  "/open/poison/npc/pig2.c" : 1,
   "/open/poison/npc/pig1.c" : 1,
]));

  setup();
}
