inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("损坏的武器",({"broken weapon","broken"}));
	set("long","一副已经损坏不堪使用的武器。\n");
	set("unit","副");
	set("value",1);
	set_weight(5000);
	setup();
}
