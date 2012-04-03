inherit ROOM;
int have = 1;
int time = 0;
#include <ansi.h>

void create ()
{
        set ("short", "天外福地");
        set ("long", @LONG
洞天之中，还有这样一块令人感觉清静的地方，一股幽香的味道
隐隐的从一处花丛中传来，却不知有什么样的东西藏在里面，而在这
福地之中，透出一股令人清爽的气味，令你忘怀一切不愉快。
LONG);
        set("outdoors", "");
        set("exits", ([ /* sizeof() == 1 */
        "west"     : __DIR__"mon30",

]));
        setup();
        set_heart_beat(1); 

}
void init()
{
    add_action("search_here", "search");
//    add_action("pull_it","pull");
} 
int search_here(object me,string arg)
{
    me=this_player();
    if( (this_player()->query("combat_exp",1) > 1000000)  && have)
    tell_object(me,"你轻轻拨开奇异的花丛，终于在花丛中发现了一棵千年灵芝。\n"+
            "此时你正在寻思要如何拔起它(pull it)。\n");
    else
    tell_object(me,"也许是你的江湖历练不足，你什么也没发现...\n");
    return 1;
}
int pull_it(string arg)
{
    object me,ob;
    me = this_player();
    if( (me->query("combat_exp",1) > 30000)  && have)
    {
    ob=new("/open/mon/npc/beast.c");
    have = 0;
    ob->move("/open/mon/mon31");
    message_vision("正当$N靠近灵芝时，只见灵芝幻化成一只仙兽向你冲了过来！！\n", me);
    return 1;
    }
    return 0;
}   
void heart_beat()
{
time++;
if(time > 300)
{
time = 0;
have = 1;
}
return;
}

