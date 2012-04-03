// liu_dart.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("柳叶镖", ({ "thin dart", "dart" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("base_unit", "枚");
		set("unit", "枚");
		set("value", 1800);
		set("material", "steel");
		set("long", "这是一枚十分细长的飞镖，平时可以藏在袖中，以发挥出绝佳的奇袭效果。\n");
		set("wield_msg", "$N暗暗的握紧了袖中的$n。\n");
		set("unwield_msg", "$N将手中的$n收回袖中。\n");
	}
	init_throwing(60);
	set_amount(1);
	setup();
}
