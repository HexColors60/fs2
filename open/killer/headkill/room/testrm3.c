#include <room.h>
inherit ROOM;

void create()
{
	set("short","风之试炼场");
	set("long",@LONG
	许多的龙卷风环绕着这一个试炼场，强烈的旋风令你站不住脚。
	唯一只有在试炼场中的石版上，你才感到较弱的风力。
	有一个风之尸魂人在此处把守，没有两把刷子，还是尽快放弃这一个任务吧！
	否则死在这里，可能连装备没机会捡回来了！

LONG);
      
set("objects",([
    "/open/killer/headkill/npc/w_ghost":1,
		]));
	set("light_up",10);
        setup();
}