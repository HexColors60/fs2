#include <ansi.h>
inherit ROOM;
void create ()
{
set("short",BLU"死灵幽谷"HIW"□白洞□"NOR);
set("long",@LONG
永无止尽的路, 永无止尽的走着, 四周依旧是白茫茫
的一片, 永远都看不到的尽头是你目前生命中搜索的唯一
目标...
LONG);
set("exits",([
"north":__DIR__"g-h12",
"south":__DIR__"g-h13",
"east":__DIR__"g-h14",
"west":__DIR__"g-h15",
]));
set("no_transmit",1);
set("ghost-hole/can_use_flute",1);
setup();
}

void init()
{
object me=this_player();
object ob=this_object();
int i,j;
if(present("evil-ghost",environment(me)))
return ;
ob=new(__DIR__"npc/evil-ghost");
ob->move(environment(me));
message_vision(HIR"邪灵突然冒出来, 狠狠的往$N身上划了一刀!!\n"NOR,me);
me->add("kee",-150);
COMBAT_D->report_status(me);
return ;
}

int valid_leave(object me,string dir)
{
me=this_player();
if(present("evil-ghost",environment(me)))
{
tell_object(me,HIW"邪灵挡住了你的去路!!\n"NOR);
return 0;
}
return 1;
}
