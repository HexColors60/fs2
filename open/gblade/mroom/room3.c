// Room: /u/m/moner/room/room3.c
inherit ROOM;

void create ()
{
  set ("short", "兵器室");
  set ("long", @LONG

这里是魔刀的兵器室，墙上挂满了刀、枪、剑、爪、等武器，倚墙处有一个兵器架
(shelf)，大大小小的刀刃散放其上，屋外射入了一丝的阳光，映照在兵器上慑慑生
威，令人望而生畏。
而生畏。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
"shelf" : "一个堆满兵器的架子，私乎可以推的样子。
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"room4.c",
]));

  setup();
}

void init()
{
add_action ("do_push","push");
}

int do_push (string str)
{
  object        me;
   if (!str || (str != "shelf" && str != "兵器架"&& str != "架子"))
return notify_fail("哇咧．．没事不要乱推！\n
");

  me = this_player();
    message_vision("地上突然出现一个洞，你来不及跳开便摔了下去!!\n", me);
    me->move(__DIR__"room5.c");
    tell_room(environment(me), sprintf ("%s像棵石头般摔了下来 .\n",
        me->short()), me);
  return 1;
}
