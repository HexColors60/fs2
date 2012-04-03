// Room: /u/m/moner/water/room2.c
inherit ROOM;

void create ()
{
  set ("short", "瀑布");
  set ("long", @LONG

细细的清泉顺着山势, 汇少成多, 川流至此, 形成一道天然的瀑布，
水花不断的溅上你的衣裳, 小径因长年的水气早以泥滑不堪了, 若非脚步
隐健的人倒也不易站隐。 从坡上往下腑视, 但见青石泻玉, 云雾袅绕, 脚
落处有一把藤蔓(robe)向谷底沿深。

LONG);

  set("light_up", 1);
  set("outdoors", "wind");
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room1.c",
]));

  setup();
}
void init()
{
  add_action ("do_climb","climb");
}

int do_climb (string str)
{
  object    me;
if(str!="robe")
return notify_fail("你又不是乌龟，干麻用爬的！\n");

  me = this_player();
message_vision("$N双手拉住藤蔓，咻一声溜下谷底。\n",me);
me->move(__DIR__"room3.c");
tell_room(environment(me), sprintf ("%s抓着藤蔓，很小心滑了下来。\n",
    me->short()), me);
  return 1;
}
