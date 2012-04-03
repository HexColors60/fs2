
#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
	set_name("人篸",({"ginseng"}) );
	set("base_weight", 50);
	set("unit","根");
	set("base_unit","根");
	set("value",1000);
	set_amount(1);
	set("long","
一根从深山中掘得的人篸，人篸对于人体健康有相当的帮助，是高级的补品
，但因其寻得不易，相对的价格亦高，寻常人家不是轻易买的起的。\n");
	setup();
}
void init()
{
	if ( this_player()==environment() )
	add_action("do_eat","eat");
}
int do_eat(string str)
{
	object me=this_player();
	int num=10+random(5);
	if ( !str || str!="ginseng") {return 0;}
	message_vision("$N吃下人篸，觉得精神恢复了不少。\n",me);
	this_player()->receive_heal("gin",num);
	add_amount(-1);
	return 1;
}

