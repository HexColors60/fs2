inherit EQUIP;
#include <ansi.h>

void create()
{
	set_name(HIR"朱雀羽冠"NOR,({"rose finch's crest","crest"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","火红色的一顶羽冠，头顶处有一个朱雀模型物。\n");
		set("unit","双");
		set("value",2000);
		set("material","crimsonsteel");
		set("wear_msg",HIR"$N戴上$n"HIR"，头顶上的朱雀模型转红了。\n"NOR);
		set("unequip_msg",HIR"$N脱下了$n"HIR"，红色的朱雀模型缓缓消逝了。\n"NOR);
		set("armor_prop/force",5);
		set("armor_prop/armor",-20);
	        set("armor_type","head");
	}
	setup();
}