// Room: /u/u/unfinished/room/is11.c
inherit ROOM;

void create ()
{
  set ("short", "小瀑布");
  set ("long", @LONG
来到这里, 此处的树木已没有那么的郁密遮天. 此地三面被山壁所包围, 少
量的水源从东面的山壁流出, 形成一条小瀑布(waterfall),看来就算短时间内船
只无法修复, 饮水应该也不成问题了. 这里三面是山, 一面是森林, 海风不侵, 
十分暖活.
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "waterfall" : "一条由山壁流出的小瀑布,水质澄清,并非海水,用来饮用(drink)应该没问题.
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"is10",
]));
  set("outdoors", "/u/u");

  setup();
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink()
{
        object who;
        who = this_player();
                  if ((int)who->query("water") >= (int)who->max_water_capacity())
          {
            tell_object(who,"喝那么多水干麻?!乱喝水小心长蛔虫!!\n");
            return 1;
          }
            tell_object(who,"\n你从瀑布中喝了一些水....味道不是很好!!\n");
            who->add("water",50);
            return 1;
}
