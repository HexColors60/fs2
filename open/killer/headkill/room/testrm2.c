#include <room.h>
inherit ROOM;

void create()
{
	set("short","水之试炼场");
	set("long",@LONG
	你几乎不敢相信你的眼睛，因为这一个试炼场，居然是在水底？
	四周只有着清澈的海水所包围着，但是，海水居然不会吞没此处？
	但是，看到一旁的石碑上刻着‘天才小渡建造’，你以明白了一切。
	水之尸魂人在此处把守，如果没有两把刷子，还是尽快放弃这一个任务吧！
	否则死在这里，可能连装备没机会捡回来了！
LONG);
      
set("objects",([
    "/open/killer/headkill/npc/i_ghost":1,
		]));
	set("light_up",10);
        setup();
}