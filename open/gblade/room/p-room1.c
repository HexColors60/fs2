// Room: /open/gblade/room/p-room1.c
inherit ROOM;
string do_look();

void create ()
{
  set ("short", "密室");
  set ("long", @LONG
阴暗封闭的密室，因长年无人涉足，而充斥着一股令人闷塞的气息，
暗淡的光线穿过虚浮的尘埃，映在凹凸的岩壁上，隐约间可见密室中央放
着一个玄铁盒(box)，黝黑的外表拖着长长的影子，直到幽暗的角落里。

LONG);
        set("item_desc",([
        "box" : (: do_look :),
        ]));

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"p-room",
]));
  set("light_up", 1);

  setup();
}
void init()
{
        add_action("do_break","break");
}
string do_look()
{
        if(this_player()->query("lotch")>3)
        return "你发现盒子内空空如也 , 哪有什么炼妖壶 !\n";
        if(this_player()->query("lotch")<2)
        this_player()->set("lotch",2);
        return "
这个盒子为千年玄铁所制 ,看来非得找一把神兵利器才能将它打(break)
开! 难不成里面藏着传说中的炼妖壶 ? \n";
}
int do_break(string str)
{
        if(!str||str!="box")
        return notify_fail("你要打开什么 ?\n");
        if(!present("dragon-tiger blade",this_player() ) )
        return notify_fail("找到龙虎刀再说吧 !\n");
        if(this_player()->query("lotch")>3)
        return notify_fail("这个盒子已经被你打开了 !\n");
        message_vision("$N手持龙虎刀 , 往盒子一砍 !\n",this_player() );
        message_vision("千年玄铁为龙虎刀所破 , $N将盒子打开 !\n",this_player()
 );
        this_player()->set("lotch",4);
return 1;
}
