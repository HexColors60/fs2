// s_pill.c by oda

#include </open/open.h>
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("药丸", ({ "pill" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一颗从万神医那边偷出来的药丸，吃下去也许有什么神奇的功效。\n");
		set("unit", "颗");
		set("食物", ([
                        // "剩" : 4,       // 可以吃几口
                        // "供应": 40,     // 每一口填饱肚子的量
                        "额外函数" : "do_eat",
                ]) );
	}
	setup();
}

int do_eat(object me, string arg)
{
	if( !arg || arg!="pill" )
		return 0;
	message_vision("$N拿起药丸，不管三七二十一的就往肚子里吞。\n", me);
	tell_object(me, "你感觉到全身突然热血沸腾，难道是神药的功效让你增加了一甲子的功力吗？\n");
	this_object()->move(BAD_ROOM"temp");
	call_out("eat_pill", 3, me);
	return 1;
}

int eat_pill(object me)
{
	tell_object(me, "\n糟了，怎么感觉不太对劲，刚刚那个药丸....\n");
	tell_object(me,HIC"不好了，你刚刚吃的是江湖上最厉害的春药‘阴阳合和散’！\n"NOR);
	tell_object(me,HIC"\n你感到全身气血翻腾，内力全失。\n"NOR);
	me->set("force", 0);
	me->apply_condition("spring", 10);
	destruct(this_object());
	return 1;
}
