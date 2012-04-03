//	manque_sword.c		designed by dos	 95'12

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("失意剑", ({ "manque sword","sword"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是失意剑客的剑, 剑端有时候会滴着水,
就好像是流眼泪\似的. \n");
		set("value", 1500);
		set("material", "gold");
	}
	init_sword(40);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N唰的一声, 把剑抽了出来, 紧紧的握在手中. \n");
	set("unwield_msg", "$N把握在手上的$n缓缓的差入剑鞘. \n");

// The setup() is required.

	setup();
}
