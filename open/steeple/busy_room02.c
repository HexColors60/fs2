inherit ROOM;
void create ()
{
set("short", "休息间");
set("long",@LONG

经过了一番打斗来到了这个房间，一片空荡荡的空房，
完全没有任何东西的摆设，这里就是试炼塔塔主火神舞
为了减轻系统所做出来的系统缓冲区。

LONG);
set("exits", ([
"north" : __DIR__"up02",
"down" : __DIR__"up01",
]));
set("objects",([
__DIR__"checkman":1,
]));
set("no_die_room",1);
set("light_up",1);
set("no_transmit",1);
set("no_auc", 1);
set("no_fight",1);
setup();
}

void init()
{
object me=this_player();
me->start_busy(3);
}