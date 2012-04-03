#include <weapon.h>
#include <ansi.h>
inherit DAGGER;


void create()
{
	set_name("花剪", ({"scissors"}) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else{
		set("unit", "把");
		set("long", "这是园丁用来修剪花草所用的工具.\n");
		set("value", 100);
		set("material", "steel");


	set("wield_msg", "$N装备花剪当武器.\n");
	set("unwield_msg", "$N将手中的$n放下.\n");
	}
	init_dagger(5);

	setup();
}
