#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","新手练功区");
  set ("long", @LONG
这个地方是受到天神祝福的区域，来到这里你，看到一堆和你一样的狂想菜鸟
正拿着武器拼命的与这里的练功兽练习。看来你是来对地方了，赶快拿出你的武器
跟这些练功兽一起练功吧！希望你早日成为狂想空间里的一代大侠。
                                                          狂想巫师群敬上
LONG);

  set("objects", ([ /* sizeof() == 1 */
      "/open/start/npc/protectman" : 1,
]));
  set("exits", ([ /* sizeof() == 5 */
  "north" : __DIR__"newhand2.c",
  "south" : __DIR__"newhand8.c",
  "east" : __DIR__"newhand6.c",
  "west" : __DIR__"newhand4.c",
  "out" : "/open/trans/room/room4.c",
  
]));
  set("no_transmit", 1);
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);

  setup();
}
int valid_leave(object who, string dir)
{
	if (dir == "out")
	{
		if(who->query("combat_exp")>20000)
		{
		  message_vision( HIY"\n天神取走$N身上多余的经验值!!\n"NOR,who); 
	          who->set("combat_exp",20001);
	        }
        }
        return :: valid_leave(who,dir);
}