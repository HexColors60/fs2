inherit EQUIP;
#include <ansi.h>

void create()
{
	set_name(HIR"朱雀羽衣"NOR,({"rose finch's cloth","cloth"}));
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","火红色的一件宝衣，于衣中央画有朱雀的图样。\n");
		set("unit","双");
		set("value",2000);
		set("material","crimsonsteel");
		set("wear_msg",HIR"$N穿上$n"HIR"，衣上的朱雀图样转红了。\n"NOR);
		set("unequip_msg",HIR"$N脱下了$n"HIR"，红色的朱雀图样缓缓消逝了。\n"NOR);
		set("armor_prop/force",5);
		set("armor_prop/armor",-20);
	        set("armor_type","cloth");
	}
	setup();
}