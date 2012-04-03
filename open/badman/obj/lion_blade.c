// lion_blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("狮王战刀", ({ "lion blade", "blade" }) );
	set_weight(12000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 4000);
		set("material", "steel");
		set("long", "这是一柄巨大的战刀，刀身足足有三尺长，重逾百斤，一般人恐怕难以使得动。\n");
		set("wield_msg", "$N双手握住背上的刀柄，真气一提将$n抽了出来握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回背后的刀鞘中。\n");
	}
	init_blade(70, TWO_HANDED);
	setup();
}
