// besttea.c by ACKY

#include <ansi.h>

inherit ITEM;
////inherit F_LIQUID;

int extra_func();
int drink_func();

void create()
{
	set_name("纯吃茶", ({ "tea" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set( "long", "一壶清凉解渴的特级冻顶乌龙茶。\n" );
		set( "unit", "壶" );
		set( "value", 1000 );
		set( "饱和", 20 );
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("液体", ([
		"种类"		: "茶",
		"名称"		: "特级冻顶乌龙茶",
		"剩"		: 20,
		"止渴"		: 100,
		"饮用讯息"	: (: drink_func :),
		"额外函数"	: (: extra_func :)
	]) );
        setup();
}

int extra_func()
{
	if( !query("液体/剩") ) {
		write( "这壶茶已经被你喝光了, 你运劲于指, 将其震得粉碎。\n" );
		destruct( this_object() );
		return 1;
	}
	return 0;
}

int drink_func()
{
	object me = this_player();
	message_vision( HIC"$N拿出纯吃茶, 张口轻轻运劲, 一道清凉的水柱喷进$P嘴里, 哇, 真是透心凉啊。\n"NOR, me );
	return 1;
}
