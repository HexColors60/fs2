inherit ROOM;

void create()
{
	set("short","蛇寨 三层大厅");
	set("long",@LONG
通道上，挤满了许多种类的毒蛇，不过大多不会攻击人，而通道
上却摆满了许多雕刻精美的石雕，石雕雕硕之精美，连他脸上的皱折
都可以清晰的看见，但是..似乎都不像是人间界的生物石雕..
LONG);
	set("no_transmit",1);
	set("objects",([
__DIR__"npc/snake_guard_1":1,
__DIR__"npc/snake_guard_2":1,
]));
	set("exits",([
"south":__DIR__"r-65",
"north":__DIR__"r-67",
]));
	setup();
}

int valid_leave(object me,string dir)
{
	if( present("snake-guard",environment(me)) )
	{
		message_vision("长老大喝："+me->name(1)+"想往哪跑～给我站住～\n",me);
		return notify_fail("你的退路已经被挡住了。\n");
	}
return 1;
}
