// Room: /open/gsword/room/gsword5-7.c
inherit ROOM;

void create ()
{
  set ("short", "二楼楼梯口");
  set ("long", @LONG
中间一条木梯 ,相当精致 ,南边的长廊分别连接仙剑七侠之寝居 ,楼上则是掌
门人 --- 郑士欣之寝居 ,楼梯旁种满了花卉 ,远远看去 ,实在赏心悦目 .北边开了
个大窗户 ,外面正是仙剑的后花园,和风栩栩 ,满室芳香 ,住在此地 ,着实享受 .

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : "/open/gsword/room/g3-15.c",
  "up" : "/open/gsword/room/g3-13.c",
  "down" : "/open/gsword/room/g3-11.c",
]));

  set("light_up", 1);

  setup();
}
